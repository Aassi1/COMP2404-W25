#ifndef FLOWPANEL_H
#define FLOWPANEL_H

#include "TextArea.h"
#include "TAArray.h"
#include "X11/Xlib.h"
#include "defs.h"
#include <string>


class FlowPanel {
    public :
        FlowPanel(int x, int y, int width, int height, string id, int xgap = 10, int ygap = 10);
        FlowPanel(Rectangle rectangle, string id, int xgap = 10, int ygap = 10);
        FlowPanel(FlowPanel &other); 
        ~FlowPanel();

        bool addTextArea(TextArea* ta);
        bool addTextArea(TextArea* ta, int index);
        TextArea* getTextArea(std::string id);
        TextArea* getTextArea(int index);
        TextArea* removeTextArea(std::string id);
        TextArea* removeTextArea(int index);


        bool overlaps(FlowPanel &other) const;
        void draw(Display *display, Window win, GC gc);
        void draw(Display *display, Window win, GC gc, int x, int y);

        string getId() const { return id; }
        int getX() const { return dimensions.x; }
        int getY() const { return dimensions.y; }
        int getWidth() const { return dimensions.width; }
        int getHeight() const { return dimensions.height; }
        
        void print() const;
        void printTextAreas() const;

    private :
        std::string id;
        Rectangle dimensions;
        int xgap, ygap;
        TAArray areas;

};
#endif
