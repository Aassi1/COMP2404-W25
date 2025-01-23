#include "RGB.h"
#include "defs.h"
using namespace std;
#include <iostream>

RGB::RGB(int r, int g, int b){
    this->r = r;
    this->g = g;
    this->b = b;
};

RGB::RGB(CuColour c){
    this->r = (c>>16)&0b11111111;
    this->g = (c>>8)&0b11111111;
    this->b = c&0b11111111;
};

RGB::RGB(){
    this->r = 0;
    this->g = 0;
    this->b = 0;
};

CuColour RGB::getColour() const{
    return (r<<16) + (g<<8) + b;
};

void RGB::setColour(CuColour c){
    this->r = (c>>16)&0b11111111;
    this->g = (c>>8)&0b11111111;
    this->b = c&0b11111111;
};

int RGB::getR() const{
    return r;
};

int RGB::getG() const{
  return g;  
};

int RGB::getB() const{
    return b;
};

void RGB::setR(int r){
    this->r = r;
}

void RGB::setG(int r){
    this->r = r;
}

void RGB::setB(int r){
    this->r = r;
};

void RGB::print(){
    cout << "R: " << r << endl;
    cout << "G: " << g << endl;
    cout << "B: " << b << endl;
    cout << "Colour: " << getColour() << endl;
    cout << "CuColour: " << (r<<16) + (g<<8) + b << endl;
};