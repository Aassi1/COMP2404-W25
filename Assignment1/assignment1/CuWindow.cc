#include "CuWindow.h"
#include <iostream>
#include <X11/Xlib.h>
#include <unistd.h>
#include <string>
#include "defs.h"


using namespace std;

// Custom function that I created that starts a display, this code is taken from birdhouse.cc but I added an error check since for some reason it was not working. Turns out there
// is a bug with X11 on ssh therefore something is off about it and it does not function properly.
void CuWindow::startDisplay() {
    display = XOpenDisplay(NULL);
    if (!display) {
        cout << "Error: Unable to open X display. Make sure the X server is running." << endl;
        exit(1); 
    }

    // Creating the window
    window = XCreateSimpleWindow(display,
                                 RootWindow(display, 0),
                                 0, 0,
                                 width, height,
                                 0,
                                 0x000000,
                                 0xFFFFFF);

    // Naming the window
    XStoreName(display, window, "Assignment 1 testing");
    // Creating the grapgraphics context
    gc = XCreateGC(display, window, 0, NULL);
    // Mapping the window to the screen
    XMapWindow(display, window);
    // Flushing the display so that it is visible
    XFlush(display);
    usleep(20000);
    sleep(1);
}


// Constructor for CuWindow with RGB as a background value and calling the startDisplay function
CuWindow::CuWindow(string name, int width, int height, RGB background){
    this->width = width;
    this->height = height;
    this->name = name;
    this->background = background;
    this->numOfPanels = 0;
    startDisplay();
};
// Constructor for CuWindow with CuColour as a background value and calling the startDisplay function
CuWindow::CuWindow(string name, int width, int height, CuColour background){
    this->width = width;
    this->height = height;
    this->name = name;
    this->background = background;
    this->numOfPanels = 0;
    startDisplay();
};

// addPanel function that adds a panel to the window. It will loop through the panels array and check if the panel overlaps with any other panel. If it does not overlap or if it is out of bounds.
bool CuWindow::addPanel(Panel& p){
    // Check if the panel overlaps with any other panel
    for (int i = 0; i <numOfPanels; i++){
        // If the panel overlaps with any other panel, return false
        if (panels[i].overlaps(p)){
            return false;
        };
    };
    // Checking if the panel is within the window, if not return false
    if (p.getX() + p.getWidth() > width || p.getY() + p.getHeight() > height || p.getX() < 0 || p.getY() < 0){
        return false;
    };
    // Checking if there is enough space in the panel array to add a panel, if not return false
    if (numOfPanels >= MAX_COMPONENTS){
        return false;
    }
    // Adding the panel to the array and returning true
    panels[numOfPanels] = p;
    numOfPanels++;
    return true;
};

// removePanel function that removes a panel from the window. This is very similar to the removeButton function in the Panel class
bool CuWindow::removePanel(string id){
    for (int i = 0; i < numOfPanels; i++){
        // if the panels id matches the id that is given as a parameter, loop through the remaining elements and shift then back one, then decrement the number of panels
        if (panels[i].getId() == id){
            for (int j = i; j < numOfPanels -1; j++){
                panels[j] = panels[j+1];
            };
            // decrementing the number of panels and returning true indicating that a panel was removed
            numOfPanels--;
            return true;
        };
    };
    // Return false otherwise
    return false;
};

// getPanel function that returns a pointer to the panel with the given id
Panel* CuWindow::getPanel(string id){
    // Loop through the panels array and return the panel with the given id
    for (int i = 0; i <numOfPanels; i++){
        if (panels[i].getId() == id){
            // returning a pointer to the panel with the given id
            return &panels[i];
        };
    };
    // if no pointer with that id, return a nullpointer
    return nullptr;
};

// Draw function that will draw the elements on the window
void CuWindow::draw(){
    usleep(100000);
    // setting the background colour and filling the rectangle with that colour
    XSetForeground(display, gc, background.getColour());
    XFillRectangle(display, window, gc, 0, 0, width, height);

    // Drawing the panels if they are not empty, if so it will not draw them, this is to avoid drawing empty panels
    for (int i = 0; i < numOfPanels; i++){
         if (!panels[i].getId().empty()) {
            panels[i].draw(display, window, gc);
        };
    };
    // Flushing the display so that it is visible
    XFlush(display);
};

// Basic print function that prints the name of the window and the number of panels in the window
void CuWindow::print(){
    cout << "Name: " << name << endl;
    cout << "Number of Panels: " << numOfPanels << endl;
};

// printPanels function that prints the panels in the window
void CuWindow::printPanels(){
    for (int i = 0; i < numOfPanels; i++){
        cout << "Panel " << i << endl;
        panels[i].print();
    };
};

// printPanelButtons function that prints the buttons in the panel
void CuWindow::printPanelButtons(Panel& p){
    for (int i = 0; i < p.getNumOfButtons(); i++){
        cout << "Button " << i << endl;
        p.getButton(i).print();
    }
};

// Destructor that closes the display and frees the memory
CuWindow::~CuWindow() {
    XFreeGC(display, gc);
    XUnmapWindow(display, window);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
}

