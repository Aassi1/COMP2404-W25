#ifndef FLOWPANEL_H
#define FLOWPANEL_H

#include "TextArea.h"
#include "TAArray.h"
#include "X11/Xlib.h"
#include "defs.h"
#include <string>


class FlowPanel {
    public :
        FlowPanel(int x, int y, int width, int height, const string& id, int xgap = 10, int ygap = 10);
        FlowPanel(const Rectangle& rectangle, const string& id, int xgap = 10, int ygap = 10);
        FlowPanel(const FlowPanel& other); 
        ~FlowPanel();

        bool addTextArea(TextArea* ta);
        bool addTextArea(TextArea* ta, int index);
        TextArea* getTextArea(const string& id);
        TextArea* getTextArea(int index);
        TextArea* removeTextArea(const string& id);
        TextArea* removeTextArea(int index);


        bool overlaps(const FlowPanel &other) const;
        void draw(Display *display, Window win, GC gc) const;

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
