#include "RGB.h"
#include "defs.h"
using namespace std;
#include <iostream>
#include <X11/Xlib.h>

// RGB constructor use to initialise RGB object as well as make sure that the values are are in between 0 and 255
RGB::RGB(int& r, int& g, int& b){
    this->r = r;
    this->g = g;
    this->b = b;
    if (r < 0 || r > MAX_COMPONENTS || g < 0 || g > MAX_COMPONENTS || b < 0 || b > MAX_COMPONENTS){
        cout<<"Values must be in between 0 and 255 (inclusive)"<<endl;
        
    }
}

// RGB constructor use to initialise RGB object using a CuColour as a parameter instead of 3 integers representing the values of r, g, and b
RGB::RGB(CuColour& c){

    // Here we have to bitshift since we are using a 3 byte integer to represent the colour, each byte represents the r, g, and b values
    this->r = (c>>16)&0b11111111;
    this->g = (c>>8)&0b11111111;
    this->b = c&0b11111111;
};

// Default constructor for RGB class
RGB::RGB(){
    this->r = 0;
    this->g = 0;
    this->b = 0;
};

// The getColour() funciton that will return the colour in the form of a CuColour
CuColour RGB::getColour() const{
    return (r<<16) + (g<<8) + b;
};

// The setColour() function that will set the colour of the RGB object to the colour passed in as a parameter
void RGB::setColour(CuColour& c){
    this->r = (c>>16)&0b11111111;
    this->g = (c>>8)&0b11111111;
    this->b = c&0b11111111;
};

// Here we just have getters for each of R, G and B
int RGB::getR() const{
    return r;
};

int RGB::getG() const{
  return g;  
};

int RGB::getB() const{
    return b;
};


// Basic print function that will print the values of r, g and b as well as the colour and the CuColour
void RGB::print(){
    cout << "R: " << r << endl;
    cout << "G: " << g << endl;
    cout << "B: " << b << endl;
    cout << "Colour: " << getColour() << endl;
    cout << "CuColour: " << (r<<16) + (g<<8) + b << endl;
};