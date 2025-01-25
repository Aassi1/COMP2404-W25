#ifndef BUTTON_H
#define BUTTON_H
#include <string>
#include "RGB.h"
#include "defs.h"
#include <X11/Xlib.h>


using namespace std;


class Button {

    public:
        Button(int x, int y, int width, int height, std::string label, RGB fill, RGB border);
        Button(int x, int y, int width, int height, std::string label, CuColour fill, CuColour border);
        Button();

        int getX();
        int getY();
        int getWidth();
        int getHeight();
        string getLabel();
        RGB getFill();
        RGB getBorder();
        CuColour getFillCu();
        CuColour getBorderColour();

        int getX() const{
            return x;
        };
        int getWidth() const{
            return width;
        };
        int getY() const{
            return y;
        };
        int getHeight() const{
            return height;
        };
        string getLabel() const{
            return label;
        }
        // void setX(int x);
        // void setY(int y);
        // void setWidth(int width);
        // void setHeight(int height);
        // void setLabel(std::string &newLabel);
        // void setFill(RGB fill);
        // void setBorder(RGB border);
        // void setFill(CuColour fill);
        // void setBorder(CuColour border);

        void draw(Display *display, Window win, GC gc, int parentX, int parentY);
        bool overlaps(Button& b);
        void print();

    private:
        int x;
        int y;
        int width;
        int height;
        std::string label;
        RGB fill;
        RGB border;
};
#endif