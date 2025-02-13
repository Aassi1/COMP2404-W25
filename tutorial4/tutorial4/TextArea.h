#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <iostream>
#include <string>
using namespace std;

class TextArea{
    public:
    TextArea(int x, int y, int width, int height, string id, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
    TextArea(Rectangle &rect, string id, string lable, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());

    private:
        Rectangle dimensions;
        string text;
        string id;
        RGB fill;
        RGB border;
};
#endif