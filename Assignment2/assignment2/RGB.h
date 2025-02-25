#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB{
    public :
        RGB(int r, int b, int g);
        RGB(CuColour colour);
        RGB();
        int getR() const;
        int getG() const;
        int getB() const;
        void setR(int r);
        void setB(int b);
        void setG(int g);
        void setColour(CuColour colour);

        unsigned long getColour() const;

        static RGB WHITE();
        static RGB BLACK();
        static RGB RED();
        static RGB GREEN();
        static RGB BLUE();

    private:
        int r;
        int b;
        int g;

};

#endif