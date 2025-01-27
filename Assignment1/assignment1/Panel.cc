#include "Panel.h"
#include "defs.h"
#include <iostream>
#include <X11/Xlib.h>

using namespace std;

// Getter functions that return the values of the variables
int Panel::getX() const{
    return x;
}
int Panel::getY() const{
    return y;
}
int Panel::getWidth() const{
    return width;
}
int Panel::getHeight() const{
    return height;
}
string Panel::getId() const{
    return id;
}
Button Panel::getButton(int i) const{
    return buttons[i];
}
int Panel::getNumOfButtons() const{
    return numOfButtons;
}

// Constructor and function definitions
Panel::Panel(int x, int y, int width, int height, string id){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->id = id;
    this->numOfButtons = 0;
}

// Empty constructor that intializes the variables to 0 or empty
Panel::Panel(){
    this->x = 0;
    this->y = 0;
    this->width = 200;
    this->height = 100;
    this->id = " ";
    this->numOfButtons = 0;
}

// addButton function that will add a button to the panel
bool Panel::addButton(Button& bttn){
    // Looping through the array of buttons to see if the button overlaps with any of the existing buttons, we check this using the overlaps function that we created in the button class 
    for (int i = 0; i<numOfButtons;i++){
        // Here we are checking if the button overlaps with any of the existing buttons, return false.
        if (buttons[i].overlaps(bttn)){
            cout << "Button overlaps with existing button" << endl;
            return false;
        };
    };
    //if the button exists outside of the panel constraints, then we return false
    if (bttn.getX() + bttn.getWidth() > width || bttn.getY() + bttn.getHeight() > height){
        cout<<"Button is outside of the panel :"<< bttn.getLabel() << endl;
        return false;
    }
    // Also checking if we have space in our button arary to add the button, if not we return false.
    if (numOfButtons >= MAX_COMPONENTS){
        cout << "Button array is full" << endl;
        return false;
    }
    // Adding the button to the array of buttons and incrementing the number of buttons as well as returning true
    buttons[numOfButtons] = bttn;
    numOfButtons++;
    cout << "Button added to panel" << endl;
    return true;
};

// removeButton function that will remove a button from the panel. This function gets finds the button with the given id and then shifts all the buttons after it to the left in order to "remove" it from the array
bool Panel::removeButton(string id){
    for (int i = 0; i<numOfButtons;i++){
        // if the button's id matches the one that is given as a parameter, we shift all the buttons after it to the left in order to "remove" it from the array
        if (buttons[i].getLabel() == id){
            for (int j = i; j < numOfButtons - 1 ; j++){
                buttons[j] = buttons[j+1];
            };
            // decrement the size of the buttons array/the number of buttons in the array and returning true
            numOfButtons--;
            return true;
        }
    };
    // return false otherwise
    return false;
};

// This function will draw the panel and all the buttons on the panel
void Panel::draw(Display *display, Window win, GC gc){
    // Drawing the panel
    XSetForeground(display, gc, CuBlack);
    XDrawRectangle(display, win, gc, x, y, width, height);

    // Drawing the buttons on the panel
    for (int i = 0; i < numOfButtons; i++){
        buttons[i].draw(display, win, gc, x, y);
    }
};

// This function checks if the panel overlaps with another panel, it works almost the same way as the overlaps function in the button class
bool Panel::overlaps(Panel& p) {
    if (y + height <= p.y || p.y + p.height <= y || x + width <= p.x || p.x + p.width <= x) {
        return false;  
    };
    return true;  
}
// Basic print function that prints out the panel's id, position and size
void Panel::print(){
    cout << "Panel:" << id << endl;
    cout << "Position: (" << x << "," << y << ")" << endl;
    cout << "Size: (" << width << "," << height << ")" << endl;
};
// Function that prints outu all the buttons on the panel
void Panel::printButtons(){
    for (int i = 0; i < numOfButtons; i++){
        buttons[i].print();
    }
};