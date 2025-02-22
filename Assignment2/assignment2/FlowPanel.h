#ifndef FLOWPANEL_H
#define FLOWPANEL_H

#include "TextArea.h"
#include "TAArray.h"
#include "X11/Xlib.h"
#include "defs.h"
#include <string>

using namespace std;

class FlowPanel {
    public :
        FlowPanel(int x, int y, int width, int height, string id, int xgap, int ygap);
        FlowPanel(Rectangle rectangle, string id, int xgap, int ygap);
        FlowPanel(FlowPanel &other); 
        ~FlowPanel();

        bool addTextArea(TextArea& ta);
        bool addTextArea(TextArea& ta, int index);
        TextArea getTextArea(string id);
        TextArea getTextArea(int index);
        TextArea removeTextArea(string id);
        TextArea removeTextArea(int index);


        bool overlaps(FlowPanel &other);
        void draw(Display *display, Window win, GC gc);
        void draw(Display *display, Window win, GC gc, int x, int y);


        void print() const;
        void printTextArea() const;

    private :
        string id;
        Rectangle dimensions;
        int xgap, ygap;
        TAArray areas;

};
#endif
