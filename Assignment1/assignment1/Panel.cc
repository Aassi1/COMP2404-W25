#include "Panel.h"
#include "defs.h"
#include <iostream>
#include <X11/Xlib.h>

using namespace std;

int Panel::getX() const{
    return x;
}
int Panel::getY() const{
    return y;
}
int Panel::getWidth() const{
    return width;
}
int Panel::getHeight() const{
    return height;
}
string Panel::getId() const{
    return id;
}
Button Panel::getButton(int i) const{
    return buttons[i];
}
int Panel::getNumOfButtons() const{
    return numOfButtons;
}

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
    this->width = 200;
    this->height = 100;
    this->id = " ";
    this->numOfButtons = 0;
}

bool Panel::addButton(Button& bttn){
    for (int i = 0; i<numOfButtons;i++){
        if (buttons[i].overlaps(bttn) || bttn.getX() + bttn.getWidth() > width || bttn.getY() + bttn.getHeight() > height){
            return false;
        };
    };
    if (numOfButtons == MAX_COMPONENTS){
        return false;
    }
    buttons[numOfButtons] = bttn;
    numOfButtons++;
    return true;
};

bool Panel::removeButton(string id){
    for (int i = 0; i<numOfButtons;i++){
        if (buttons[i].getLabel() == id){
            for (int j = i; j < numOfButtons - 1 ; j++){
                buttons[j] = buttons[j+1];
            };
            numOfButtons--;
            return true;
        }
    };
    return false;
};

void Panel::draw(Display *display, Window win, GC gc){
    XSetForeground(display, gc, CuBlack);
    XDrawRectangle(display, win, gc, x, y, width, height);

    for (int i = 0; i < numOfButtons; i++){
        // buttons[i].draw(display, win, gc, buttons[i].getX() + x, buttons[i].getY() + y);
        buttons[i].draw(display, win, gc, x, y);
    }
};

bool Panel::overlaps(Panel& p) {
    if (y + height <= p.y || p.y + p.height <= y || x + width <= p.x || p.x + p.width <= x) {
        return false;  
    };
    return true;  
}
void Panel::print(){
    cout << "Panel:" << id << endl;
    cout << "Position: (" << x << "," << y << ")" << endl;
    cout << "Size: (" << width << "," << height << ")" << endl;
};
void Panel::printButtons(){
    for (int i = 0; i < numOfButtons; i++){
        buttons[i].print();
    }
};