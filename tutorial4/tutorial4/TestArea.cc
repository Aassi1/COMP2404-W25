#include "TextArea.h"
#include "RGB.h"
#include "defs.h"

#include <iostream>
using namespace std;


TextArea::TextArea(int x, int y, int width, int height, string text, string id, RGB fill, RGB border){
    this->dimensions = Rectangle({x, y, width, height});
    this->text = text;
    this->id = id;
};
TextArea::TextArea(Rectangle &rect, string text, string id, string lable, RGB fill, RGB border){
    this->dimensions = rect;
    this->text = text;
    this->id = id;
}

TextArea::TextArea(){
    this->dimensions = Rectangle({0,0,0,0});
    this->text = "DUPLICATE";
    this->id = "";
}

TextArea::TextArea(const TextArea &textArea){
    this->dimensions = textArea.dimensions;
    this->id = textArea.id;
}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y){
    // Not needed to implement this method yet - just here to satisfy the compiler
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