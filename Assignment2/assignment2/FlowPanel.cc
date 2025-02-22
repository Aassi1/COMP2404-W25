#include "FlowPanel.h"
#include "TextArea.h"
#include "X11/Xlib.h"
#include "defs.h"
#include <string>


FlowPanel::FlowPanel(int x, int y, int width, int height, string id, int xgap = 10, int ygap = 10) {
    this->dimensions.x = x;
    this->dimensions.y = y;
    this->dimensions.width = width;
    this->dimensions.height = height;
    this->id = id;
    this->xgap = xgap;
    this->ygap = ygap;
}

FlowPanel::FlowPanel(Rectangle rectangle, string id, int xgap = 10, int ygap = 10) {
    this->dimensions = rectangle;
    this->id = id;
    this->xgap = xgap;
    this->ygap = ygap;
}


bool FlowPanel::addTextArea(TextArea* ta){
    if (ta){
        return areas.add(ta);
    }
    return false;
}

bool FlowPanel::addTextArea(TextArea* ta, int index){
    if (ta){
        return areas.add(ta, index);
    }
    return false;
}

TextArea* FlowPanel::getTextArea(std::string id){
    return areas.get(id);
}

TextArea* FlowPanel::getTextArea(int index){
    return areas.get(index);
}

TextArea* FlowPanel::removeTextArea(std::string id){
    return areas.remove(id);
}

TextArea* FlowPanel::removeTextArea(int index){
    return areas.remove(index);
}

// Checks if this FlowPanel overlaps with another FlowPanel
bool FlowPanel::overlaps(FlowPanel &other) const{
    return this->dimensions.overlaps(other.dimensions);
}

// Draws this FlowPanel and its TextAreas at its current position
void FlowPanel::draw(Display *display, Window win, GC gc){
    
}

// Draws this FlowPanel and its TextAreas at the specified x,y coordinates
void FlowPanel::draw(Display *display, Window win, GC gc, int x, int y){

}

// Prints information about this FlowPanel
void FlowPanel::print() const{
    cout << "FlowPanel : " << this -> id << endl;
    cout << "Position : " << this -> dimensions.x << ", " << this -> dimensions.y << endl;
    cout << "Size : " << this -> dimensions.width << ", " << this -> dimensions.height << endl;
    cout << "Num TextAreas : " << this -> areas.getSize() << endl;
}

// Prints information about the TextAreas contained in this FlowPanel
void FlowPanel::printTextArea() const{
    cout << "TextAreas : " << endl;
    for (int i = 0; i < this -> areas.getSize(); i++){
        cout << "TextArea : " << this -> areas.get(i)  << endl;
    }
}


