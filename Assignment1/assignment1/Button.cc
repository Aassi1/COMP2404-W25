#include "Button.h"
#include "defs.h"
#include <iostream>
#include <X11/Xlib.h>

using namespace std;


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
    this->width = 0;
    this->height = 0;
    this->label = "";
    this->fill = RGB(112,128,144);
    this->border = RGB(77,117,154);
};

void Button::draw(Display *display, Window win, GC gc, int parentX, int parentY){
    display = XOpenDisplay(NULL);

      win = XCreateSimpleWindow(display,                 
			    RootWindow(display, 0),  
			    0, 0,	            
			    170,200,	           
			    0, 		             
			    0x000000,                
                0xFFFFFF);               
    

};

