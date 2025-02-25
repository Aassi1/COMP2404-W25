#ifndef CUWINDOW_H
#define CUWINDOW_H

#include "X11/Xlib.h"
#include "defs.h"
#include <string>
#include "FlowPanel.h"
#include "TAArray.h"
#include "PanelArray.h"

class CuWindow{
    public : 
        CuWindow(string name, int width, int height, RGB background);
        ~CuWindow();
  
        bool addPanel(FlowPanel* panel);
        FlowPanel* removePanel(string id);
        FlowPanel* getPanel(string id);
        void draw();
        void print();
        void printPanel();
        void printPanelTextAreas();


    private : 
        int width; 
        int height;
        string name;
        PanelArray FlowPanels;
        RGB background;

        Display *display;
		Window   win;
		GC       gc;

};
#endif
