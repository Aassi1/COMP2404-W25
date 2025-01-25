#include "Panel.h"
#include "defs.h"
#include <iostream>
#include <X11/Xlib.h>

using namespace std;

Panel::Panel(int x, int y, int width, int height, string id){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->id = id;
    this->numOfButtons = 0;
}

Panel::Panel(){
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
    this->id = "";
    this->numOfButtons = 0;
}

bool Panel::addButton(Button& bttn){
    
    for (int i = 0; i<numOfButtons;i++){
        if (buttons[i].overlaps(bttn) && bttn.getX()){
            return false;
        }
    }
};

void Panel::print(){
    cout << "Panel:" << id << endl;
    cout << "Position: (" << x << "," << y << ")" << endl;
    cout << "Size: (" << width << "," << height << ")" << endl;
};