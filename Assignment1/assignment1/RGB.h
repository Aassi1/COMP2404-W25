#ifndef RGB_H
#define RGB_H
#include "defs.h"

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

        void setR(int r);
        void setG(int g);
        void setB(int b);
        void print();
        
    private:
        int r;
        int g;
        int b;

};

#endif