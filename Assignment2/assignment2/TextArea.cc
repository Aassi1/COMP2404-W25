#include "TextArea.h"
#include "RGB.h"
#include "defs.h"

#include <iostream>
using namespace std;


TextArea::TextArea(int x, int y, int width, int height, string id, RGB fill, RGB border){
    this->dimensions = Rectangle({x, y, width, height});
    this->id = id;
};
TextArea::TextArea(Rectangle &rect, string id, string lable, RGB fill, RGB border){
    this->dimensions = rect;
    this->id = id;
}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y){
    int rX = x + dimensions.x;
    int rY = y + dimensions.y;

    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, rX, rY, dimensions.width, dimensions.height);

    XSetForeground(display, gc, RGB::BLACK().getColour());
    XDrawRectangle(display, win, gc, rX, rY, dimensions.width, dimensions.height);


    XDrawString(display, win, gc, rX, rY, text.c_str(), text.length());
}
bool TextArea::overlaps(TextArea &textArea){
    return dimensions.overlaps(textArea.dimensions);
}

void TextArea::print(){
    cout << "TextArea id: " << id << endl;
    cout << "Preferred location: " << dimensions.x << ", " << dimensions.y << endl;
    cout << "Size: " << dimensions.width<< ", " << dimensions.height << endl;
    cout << "Text: " << text << endl;
}