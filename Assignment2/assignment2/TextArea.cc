#include "TextArea.h"
#include "RGB.h"
#include "defs.h"

#include <iostream>
using namespace std;


TextArea::TextArea(int x, int y, int width, int height, string id, string text, RGB fill, RGB border) {
    this->dimensions.x = x;
    this->dimensions.y = y;
    this->dimensions.width = width;
    this->dimensions.height = height;
    this->id = id;
    this->text = text;
    this->fill = fill;
    this->border = border;
}

TextArea::TextArea(const Rectangle& rect, string id, string text, RGB fill, RGB border) {
    this->dimensions = rect;
    this->id = id;
    this->text = text;
    this->fill = fill;
    this->border = border;
}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y) {
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);

    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);

    XSetForeground(display, gc, RGB::BLACK().getColour());
    int textX = x + 5;
    int textY = y + 15;  
    XDrawString(display, win, gc, x + 5, textY, text.c_str(), text.length());
}

bool TextArea::overlaps(TextArea &textArea) {
    return dimensions.overlaps(textArea.dimensions);
}

void TextArea::print(){
    cout << "TextArea id: " << id << endl;
    cout << "Preferred location: " << dimensions.x << ", " << dimensions.y << endl;
    cout << "Size: " << dimensions.width<< ", " << dimensions.height << endl;
    cout << "Text: " << text << endl;
}