#ifndef RGB_H
#define RGB_H
#include "defs.h"

//RGB class where we define our functions and the variables that we will be using
class RGB
{
    public:
        RGB(int r, int g, int b);
        RGB(CuColour c);
        RGB();

        CuColour getColour() const;
        void setColour(CuColour c);

        int getR() const;
        int getG() const;
        int getB() const;
        void print();
        
    private:
        int r;
        int g;
        int b;
};

#endif