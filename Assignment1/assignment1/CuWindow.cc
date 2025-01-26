#include "CuWindow.h"
#include <iostream>
#include <X11/Xlib.h>
#include <unistd.h>
#include <string>
#include "defs.h"


using namespace std;

// void CuWindow::startDisplay(){
//     display = XOpenDisplay(NULL);
//     window = XCreateSimpleWindow(display,                 
// 			    RootWindow(display, 0),  
// 			    0, 0,	             
// 			    width,height,	             
// 			    0, 		             
// 			    0x000000,                
//                 0xFFFFFF);               

//   XStoreName(display, window, "Assignment 1 testing");
//   gc = XCreateGC(display, window, 0, NULL);
//   XMapWindow(display, window);
//   XFlush(display);
//   usleep(20000);  
//   sleep(1);
// };

void CuWindow::startDisplay() {
    display = XOpenDisplay(NULL);
    if (!display) {
        cout << "Error: Unable to open X display. Make sure the X server is running." << endl;
        exit(1); 
    }

    window = XCreateSimpleWindow(display,
                                 RootWindow(display, 0),
                                 0, 0,
                                 width, height,
                                 0,
                                 0x000000,
                                 0xFFFFFF);

    XStoreName(display, window, "Assignment 1 testing");
    gc = XCreateGC(display, window, 0, NULL);
    XMapWindow(display, window);
    XFlush(display);
    usleep(20000);
    sleep(1);
}


CuWindow::CuWindow(string name, int width, int height, RGB background){
    this->width = width;
    this->height = height;
    this->name = name;
    this->background = background;
    this->numOfPanels = 0;
    startDisplay();
};
CuWindow::CuWindow(string name, int width, int height, CuColour background){
    this->width = width;
    this->height = height;
    this->name = name;
    this->background = background;
    this->numOfPanels = 0;
    startDisplay();
};
 
bool CuWindow::addPanel(Panel& p){
    for (int i = 0; i <numOfPanels; i++){
        if (panels[i].overlaps(p)){
            return false;
        };
    };
    if (p.getX() + p.getWidth() > width || p.getY() + p.getHeight() > height || p.getX() < 0 || p.getY() < 0){
        return false;
    };
    if (numOfPanels >= MAX_COMPONENTS){
        return false;
    }
    panels[numOfPanels] = p;
    numOfPanels++;
    return true;
};



bool CuWindow::removePanel(string id){
    for (int i = 0; i < numOfPanels; i++){
        if (panels[i].getId() == id){
            for (int j = i; j < numOfPanels -1; j++){
                panels[j] = panels[j+1];
            };
            panels[numOfPanels - 1] = Panel();
            numOfPanels--;
            return true;
        };
    };
    return false;
};

Panel* CuWindow::getPanel(string id){
    for (int i = 0; i <numOfPanels; i++){
        if (panels[i].getId() == id){
            return &panels[i];
        };
    };
    return nullptr;
};

void CuWindow::draw(){
    usleep(100000);
    XSetForeground(display, gc, background.getColour());
    XFillRectangle(display, window, gc, 0, 0, width, height);

    for (int i = 0; i < numOfPanels; i++){
         if (!panels[i].getId().empty()) {
            panels[i].draw(display, window, gc);
        }
        // if (!panels[i].getId().empty()){
        //     panels[i].draw(display, window, gc);
        // }else {
        //     cout << "Panel not found" << endl;
        // }
        // panels[i].draw(display, window, gc);
    };
    XFlush(display);
};

void CuWindow::print(){
    cout << "Name: " << name << endl;
    cout << "Number of Panels: " << numOfPanels << endl;
};

void CuWindow::printPanels(){
    for (int i = 0; i < numOfPanels; i++){
        cout << "Panel " << i << endl;
        panels[i].print();
    };
};

void CuWindow::printPanelButtons(Panel& p){
    for (int i = 0; i < p.getNumOfButtons(); i++){
        cout << "Button " << i << endl;
        p.getButton(i).print();
    }
};

CuWindow::~CuWindow() {
    if (gc) {
        XFreeGC(display, gc);
    }
    if (window) {
        XUnmapWindow(display, window);
        XDestroyWindow(display, window);
    }
    if (display) {
        XCloseDisplay(display);
    }
}

