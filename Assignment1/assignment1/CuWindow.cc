#include "CuWindow.h"
#include <iostream>
#include <X11/Xlib.h>
#include <unistd.h>
#include <string>
#include "defs.h"


using namespace std;

void CuWindow::startDisplay(){
    display = XOpenDisplay(NULL);
    window = XCreateSimpleWindow(display,                 
			    RootWindow(display, 0),  
			    0, 0,	             
			    width,height,	             
			    0, 		             
			    0x000000,                
                0xFFFFFF);               

  XStoreName(display, window, "Assignment 1 testing");
  gc = XCreateGC(display, window, 0, NULL);
  XMapWindow(display, window);
  XFlush(display);
  usleep(20000);  
  sleep(1);
};

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
        if (panels[i].overlaps(p) || p.getX() + p.getWidth() > width || p.getY() + p.getHeight() > height || numOfPanels >= MAX_COMPONENTS){
            return false;
        };
    };
    panels[numOfPanels] = p;
    numOfPanels++;
    return true;
};

bool CuWindow::removePanel(string id){
    for (int i = 0; i < numOfPanels; i++){
        if (panels[i].getId() == id){
            for (int j = i; j < numOfPanels; j++){
                panels[j] = panels[j+1];
            };
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
    XFillRectangle(display, window, gc, 0, 0, width, height);

    for (int i = 0; i < numOfPanels; i++){
        panels[i].draw(display, window, gc);
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

CuWindow::~CuWindow(){
    XFreeGC(display, gc);
    XUnmapWindow(display, window);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
};