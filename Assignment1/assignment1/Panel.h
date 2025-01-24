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
