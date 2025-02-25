#include "CuWindow.h"
#include <unistd.h>

CuWindow::CuWindow(const string& name, int width, int height, const RGB& background){
    this->name = name;
    this->width = width;
    this->height = height;
    this->background = background;

    display = XOpenDisplay(NULL);
    win = XCreateSimpleWindow(display,  RootWindow(display, 0), 0, 0,
                    width, height, 0, 0x000000, background.getColour());
    XStoreName(display, win, name.c_str());
    gc = XCreateGC(display, win, 0, NULL);
    XMapWindow(display, win);
    XFlush(display);
    usleep(20000); 
};

CuWindow::~CuWindow(){
    XFreeGC(display, gc);
    XDestroyWindow(display, win);
    XCloseDisplay(display);
    for(int i = 0; i < FlowPanels.getSize(); i++){
        delete FlowPanels.get(i);
    }
};

bool CuWindow::addPanel(FlowPanel* panel){
    if (panel->getX() + panel->getWidth() > width || 
        panel->getY() + panel->getHeight() > height) {
        return false;
    }

    for (int i = 0; i < FlowPanels.getSize(); i++) {
        FlowPanel* flowpanel = FlowPanels.get(i);
        if (panel->overlaps(*flowpanel)) {
            return false;
        }
    }
    FlowPanels.add(panel);
    return true;
};

FlowPanel* CuWindow::removePanel(const string& id){
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        if (FlowPanels.get(i)->getId() == id) {
            return FlowPanels.remove(i);
        }
    }
    return nullptr;
};

FlowPanel* CuWindow::getPanel(const string& id){
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        if (FlowPanels.get(i)->getId() == id) {
            return FlowPanels.get(i);
        }
    }
    return nullptr;
};

void CuWindow::draw() const {
    usleep(100000);
    
    XClearWindow(display, win);
    
    XSetForeground(display, gc, background.getColour());
    XFillRectangle(display, win, gc, 0, 0, width, height);
    
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        FlowPanels.get(i)->draw(display, win, gc);
    }
    XFlush(display);
}

void CuWindow::print() const {
    cout << "Window: " << name << endl;
    cout << "Number of panels: " << FlowPanels.getSize() << endl;
};

void CuWindow::printPanels() const {
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        FlowPanels.get(i)->print();
    }
};

void CuWindow::printPanelTextAreas() const {
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        FlowPanels.get(i)->printTextAreas();
    }
};