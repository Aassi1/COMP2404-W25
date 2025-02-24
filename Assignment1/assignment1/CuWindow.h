#ifndef CUWINDOW_H
#define CUWINDOW_H
#include "Panel.h"
#include <string>
#include "defs.h"
#include "RGB.h"
#include <X11/Xlib.h>
#include <unistd.h>

using namespace std;

// CuWindow is a window that can contain multiple panels, here we have the function implementations as well as the member variables
class CuWindow{
    public:
        CuWindow(string name, int width, int height, RGB background);
        CuWindow(string name, int widht, int height, CuColour background);
        ~CuWindow();

        bool addPanel(Panel& p);
        bool removePanel(string id);
        Panel* getPanel(string id);
        void draw();
        void print();
        void printPanels();
        void printPanelButtons();

        void startDisplay();

    private:
        int width;
        int height;
        string name;
        Panel panels[MAX_COMPONENTS];
        int numOfPanels;
        RGB background; 

        // For X11
        Display* display;
        Window window;
        GC gc;
};
#endif