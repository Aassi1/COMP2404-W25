#ifndef PANEL_H
#define PANEL_H
#include "RGB.h"
#include <string>
#include "Button.h"
#include "defs.h"

using namespace std;

class Panel{

    public:
        Panel(int x, int y, int width, int height, string id);
        Panel();
        bool addButton(Button& bttn);
        bool removeButton(string id);
        void draw(Display *display, Window win, GC gc);
        bool overlaps(Panel& p);
        void print();
        
        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        string getId() const;
        Button getButton(int i) const;
        int getNumOfButtons() const;
        void printButtons();

    private:
        int x;
        int y;
        int width;
        int height;
        string id;
        Button buttons[MAX_COMPONENTS];
        int numOfButtons;
};
#endif
