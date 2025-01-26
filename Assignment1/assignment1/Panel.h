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
        
        int getX() const{
            return x;
        };
        int getY() const{
            return y;
        };
        int getWidth() const{
            return width;
        };
        int getHeight() const;

        string getId() const{
            return id;
        };

        Button getButton(int i) const{
            return buttons[i];
        }

        int getNumOfButtons() const{
            return numOfButtons;
        };

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
