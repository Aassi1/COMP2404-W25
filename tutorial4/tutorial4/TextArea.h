#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>


using namespace std;

class TextArea{
    public:
    TextArea(int x, int y, int width, int height, string text, string id, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
    TextArea(Rectangle &rect, string id, string text, string lable, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
    TextArea();

    TextArea(const TextArea &textArea);
    
    void draw(Display *display, Window win, GC gc, int x, int y);
    bool overlaps(TextArea &textArea);

    void print();

    private:
        Rectangle dimensions;
        string text;
        string id;
        RGB fill;
        RGB border;
};
#endif