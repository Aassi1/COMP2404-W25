#include "RGB.h"
#include <iostream>
#include "defs.h"

using namespace std;


RGB::RGB(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

RGB::RGB(CuColour c){
    this->r = (c>>16)&0b11111111;
    this->g = (c>>8)&0b11111111;
    this->b = c&0b11111111;
};

RGB::RGB() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

CuColour RGB::getColour(){
    return (this->r<<16) | (this->g<<8) | this->b;
}

void RGB::setColour(CuColour c){
    this->r = (c>>16)&0b11111111;
    this->g = (c>>8)&0b11111111;
    this->b = c&0b11111111;
};
