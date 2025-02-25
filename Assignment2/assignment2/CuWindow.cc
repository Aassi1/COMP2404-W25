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

bool CuWindow::addPanel(FlowPanel* panel){};

FlowPanel* CuWindow::removePanel(string id){};

FlowPanel* CuWindow::getPanel(string id){};

void CuWindow::draw(){};

void CuWindow::print(){};

void CuWindow::printPanels() {
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        FlowPanels.get(i)->print();
    }
};

void CuWindow::printPanelTextAreas(){
    for (int i = 0; i < FlowPanels.getSize(); i++) {
        FlowPanels.get(i)->printTextArea();
    }
};