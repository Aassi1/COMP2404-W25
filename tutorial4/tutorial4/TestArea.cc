#include "TextArea.h"
#include "RGB.h"
#include "defs.h"

TextArea::TextArea(int x, int y, int width, int height, string id, RGB fill, RGB border){
    this->dimensions = Rectangle({x, y, width, height});
    this->id = id;
};
TextArea::TextArea(Rectangle &rect, string id, string lable, RGB fill, RGB border){
    this->dimensions = rect;
    this->id = id;
}

