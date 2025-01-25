#include "CuWindow.h"
#include <iostream>
#include <X11/Xlib.h>
#include <unistd.h>
#include <string>
#include "defs.h"
#include "RGB.h"


using namespace std;

bool CuWindow::addPanel(Panel& p){
    for (int i = 0; i <numOfPanels; i++){
        if (panels[i].overlaps(p) && p.getX() + p.getWidth() > width || p.getY() + p.getHeight() > height){
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
        }
    }
};

Panel* CuWindow::getPanel(string id){
    for (int i = 0; i <numOfPanels; i++){
        if (panels[i].getId() == id){
            return &panels[i];
        };
    return nullptr;
};

void CuWindow::draw(){
    
};