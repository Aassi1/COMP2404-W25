#include "Button.h"
#include "defs.h"
#include <iostream>
#include <X11/Xlib.h>
#include <unistd.h>

using namespace std;

// All the getter methods that will be used 
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

// Basic constrcutors for the button class, this first one takes in an RGB value for both fill and border
Button::Button(int x, int y, int width, int height, string label, RGB fill, RGB border){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->label = label;
    this->fill = fill;
    this->border = border;
};

// This constructor takes in a CuColour value for both fill and border
Button::Button(int x, int y, int width, int height, string label, CuColour fill, CuColour border){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->label = label;
    this->fill = RGB(fill);
    this->border = RGB(border);
};

// This constructor is just a blank constructor that will be used in the Panel class
Button::Button(){
    this->x = 0;
    this->y = 0;
    this->width = 100;
    this->height = 50;
    this->label = " ";
    this->fill = RGB(112,128,144);
    this->border = RGB(77,117,154);
};

// This method will draw the button on the screen
void Button::draw(Display *display, Window win, GC gc, int parentX, int parentY){
    // Set the fill color and fill the rectangle using XFillRectangle()
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x + parentX, y + parentY, width, height);

    // Set the border color
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x + parentX, y + parentY, width, height);

    // Draw the label
    XSetForeground(display, gc, CuWhite); 
    XDrawString(display, win, gc, parentX + x +10,  parentY + y + height/2, label.c_str(), label.length());
}

// This method is crucial in checking if any buttons overlap each other, if so it will return a boolean value of true
bool Button::overlaps(Button& b){   
    // Check if the two buttons overlap, here, this checks all the possible scnearios where a button is not overlaping, and returns false if they do not.
    if (y + height <=b.y || b.y + b.height <= y || x + width <= b.x || b.x + b.width <= x){
        return false;
    };
    // returns true if they end up overlaping
    return true;
};

// Basic print funciton that will print out the button, its position and its size
void Button::print(){
    cout<<"Button: "<<label<<endl;
    cout<<"Position: ("<<x<<", "<<y<<")"<<endl;
    cout<<"Size: ("<<width<<", "<<height<<")"<<endl;
}