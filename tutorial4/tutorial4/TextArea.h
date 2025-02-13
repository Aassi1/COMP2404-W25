#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include "RGB.h"
#include "defs.h"


using namespace std;

class TextArea{
    public:
    TextArea(int x, int y, int width, int height, string id, string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
    TextArea(Rectangle &rect, string id, string text, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
    TextArea();

    TextArea(const TextArea &textArea);
    
    void draw(Display *display, Window win, GC gc, int x, int y);
    bool overlaps(const TextArea &textArea);

    void print() const;

    private:
        Rectangle dimensions;
        string label;
        string id;
        RGB fill;
        RGB border;
};
#endif