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
        TextArea(int x, int y, int width, int height, const string& id, const string& text, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
        TextArea(const Rectangle& rect, const string& id, const string& text, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());

        void draw(Display *display, Window win, GC gc, int x, int y) const;

        void setFill(const RGB& fill);
        bool overlaps(const TextArea &textArea) const;
        string getId() const { return id; };
        Rectangle getDimensions() const { return dimensions; };
        string getText() const { return text; }

        
        void print() const;

        void setText(const string& text) { this->text = text; }
        void setHeight(int height) { this->dimensions.height = height; }

    private:
        Rectangle dimensions;
        string text;
        string id;
        RGB fill;
        RGB border;
};
#endif