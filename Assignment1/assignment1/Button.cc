#include "Button.h"
#include "defs.h"
#include <iostream>
#include <X11/Xlib.h>
#include <unistd.h>

using namespace std;

int Button::getX(){
    return x;
}
int Button::getY(){
    return y;
}
int Button::getWidth(){
    return width;
}
int Button::getHeight(){
    return height;
}
string Button::getLabel(){
    return label;
}

Button::Button(int x, int y, int width, int height, string label, RGB fill, RGB border){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->label = label;
    this->fill = fill;
    this->border = border;
};

Button::Button(int x, int y, int width, int height, string label, CuColour fill, CuColour border){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->label = label;
    this->fill = RGB(fill);
    this->border = RGB(border);
};

Button::Button(){
    this->x = 0;
    this->y = 0;
    this->width = 100;
    this->height = 50;
    this->label = " ";
    this->fill = RGB(112,128,144);
    this->border = RGB(77,117,154);
};

void Button::draw(Display *display, Window win, GC gc, int parentX, int parentY){   
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x + parentX, y + parentY, width, height);

    XSetForeground(display, gc, CuWhite); // Use black for text
    XDrawString(display, win, gc, (width-label.length())/2, height/2, label.c_str(), label.length());
};

bool Button::overlaps(Button& b){
    if (y + height <=b.y || b.y + b.height <= y || x + width <= b.x || b.x + b.width <= x){
        return false;
    };
    return true;
};

void Button::print(){
    cout<<"Button: "<<label<<endl;
    cout<<"Position: ("<<x<<", "<<y<<")"<<endl;
    cout<<"Size: ("<<width<<", "<<height<<")"<<endl;
}