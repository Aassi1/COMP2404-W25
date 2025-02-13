#include "TextArea.h"
#include "RGB.h"
#include "defs.h"

#include <iostream>
using namespace std;


TextArea::TextArea(int x, int y, int width, int height,  string id, string label, const RGB fill, const RGB border){
    this->dimensions = Rectangle({x, y, width, height});
    // this->text = text;
    this->id = id;
    this->label = label;
    this->fill = fill;
    this->border = border;
};
TextArea::TextArea(const Rectangle &rect, string id, string label, RGB fill, RGB border){
    this->dimensions = rect;
    // this->text = text;
    this->label = label;
    this->id = id;
    this->fill = RGB::WHITE();
    this->border = RGB::BLACK();
}

TextArea::TextArea(){
    this->dimensions = Rectangle({0,0,0,0});
    this->label = "DUPLICATE";
    this->id = "";
    this->fill = RGB::WHITE();
    this->border = RGB::BLACK();
}

TextArea::TextArea(const TextArea &textArea){
    this->dimensions = textArea.dimensions;
    this->id = textArea.id;
}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y){
    // Not needed to implement this method yet - just here to satisfy the compiler
}

void TextArea::setFill(const RGB& newFill) {
    fill = newFill;
}

void TextArea::setBorder(const RGB& newBorder) {
    border = newBorder;
}

bool TextArea::overlaps(const TextArea &textArea) const {
    return dimensions.overlaps(textArea.dimensions);
}

void TextArea::print() const{
    cout << "TextArea id: " << id << endl;
    cout << "Preferred location: " << dimensions.x << ", " << dimensions.y << endl;
    cout << "Size: " << dimensions.width<< ", " << dimensions.height << endl;
    cout << "Text: " << label << endl;
}