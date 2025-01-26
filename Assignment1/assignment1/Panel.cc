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
        if (buttons[i].overlaps(bttn) && bttn.getX() + bttn.getWidth() > width || bttn.getY() + bttn.getHeight() > height){
            return false;
        };
    };
    buttons[numOfButtons] = bttn;
    numOfButtons++;
    return true;
};

bool Panel::removeButton(string id){
    for (int i = 0; i<numOfButtons;i++){
        if (buttons[i].getLabel() == id){
            for (int j = i; j < numOfButtons; j++){
                buttons[j] = buttons[j+1];
            };
            numOfButtons--;
            return true;
        }
    };
    return false;
};

void Panel::draw(Display *display, Window win, GC gc){
    XDrawRectangle(display, win, gc, x, y, width, height);

    for (int i = 0; i < numOfButtons; i++){
        buttons[i].draw(display, win, gc, buttons[i].getX() + x, buttons[i].getY() + y);
    }
};

bool Panel::overlaps(Panel& p){
    if (y + height <=p.y || p.y + p.height <= y || x + width <= p.x || p.x + p.width <= x){
        return false;
    };
    return true;
};
 

void Panel::print(){
    cout << "Panel:" << id << endl;
    cout << "Position: (" << x << "," << y << ")" << endl;
    cout << "Size: (" << width << "," << height << ")" << endl;
};