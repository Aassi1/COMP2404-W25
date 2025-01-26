#ifndef RGB_H
#define RGB_H
#include "defs.h"

using namespace std;


class RGB {
    public:
        RGB(int r, int g, int b);
        RGB(CuColour c);
        RGB();

        int getR() {
            return r;
        };
        int getG() {
            return g;
        };
        int getB(){
            return b;
        };

        CuColour getColour();

        void setR(int r) {
            this->r = r;
        }
        void setG(int g) {
            this->g = g;
        };
        void setB(int b) {
            this->b = b;
        };

        void setColour(CuColour colour);


    private:
        int r;
        int g;
        int b;

};
#endif