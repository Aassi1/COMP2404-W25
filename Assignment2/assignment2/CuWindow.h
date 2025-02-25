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
        CuWindow(const string& name, int width, int height, const RGB& background);
        ~CuWindow();
  
        bool addPanel(FlowPanel* panel);
        FlowPanel* removePanel(const string& id);
        FlowPanel* getPanel(const string& id);
        void draw() const;
        void print() const;
        void printPanels() const;
        void printPanelTextAreas() const;

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
