#include "CuWindow.h"
#include <unistd.h>

CuWindow::CuWindow(string name, int width, int height, RGB& background){
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

FlowPanel* CuWindow::removePanel(string id){
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        if (FlowPanels.get(i)->getId() == id) {
            return FlowPanels.remove(i);
        }
    }
    return nullptr;
};

FlowPanel* CuWindow::getPanel(string id){
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        if (FlowPanels.get(i)->getId() == id) {
            return FlowPanels.get(i);
        }
    }
    return nullptr;
};

void CuWindow::draw() {
    usleep(100000);
    
    XClearWindow(display, win);
    
    XSetForeground(display, gc, background.getColour());
    XFillRectangle(display, win, gc, 0, 0, width, height);
    
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        FlowPanels.get(i)->draw(display, win, gc);
    }
    XFlush(display);
}

void CuWindow::print() {
    cout << "Window: " << name << endl;
    cout << "Number of panels: " << FlowPanels.getSize() << endl;
};

void CuWindow::printPanels() {
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        FlowPanels.get(i)->print();
    }
};

void CuWindow::printPanelTextAreas(){
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        FlowPanels.get(i)->printTextAreas();
    }
};