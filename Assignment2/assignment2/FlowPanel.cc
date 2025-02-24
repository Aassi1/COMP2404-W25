#include "FlowPanel.h"
#include "TextArea.h"
#include "X11/Xlib.h"
#include "defs.h"
#include <string>


FlowPanel::FlowPanel(int x, int y, int width, int height, const string& id, int xgap, int ygap) {
    this->dimensions.x = x;
    this->dimensions.y = y;
    this->dimensions.width = width;
    this->dimensions.height = height;
    this->id = id;
    this->xgap = xgap;
    this->ygap = ygap;
}

FlowPanel::FlowPanel(const Rectangle& rectangle, const string& id, int xgap , int ygap ) {
    this->dimensions = rectangle;
    this->id = id;
    this->xgap = xgap;
    this->ygap = ygap;
}

FlowPanel::FlowPanel(const FlowPanel& other) {
    this->dimensions = other.dimensions;
    this->id = other.id;
    this->xgap = other.xgap;
    this->ygap = other.ygap;
    for (int i = 0; i < other.areas.getSize(); i++) {
        TextArea* ta = other.areas.get(i);
        if (ta) {
            this->areas.add(new TextArea(*ta));
        }
    }
}

FlowPanel::~FlowPanel() {
}


bool FlowPanel::addTextArea(TextArea* textArea){
    if (textArea){
        return areas.add(textArea);
    }
    return false;
}

bool FlowPanel::addTextArea(TextArea* textArea, int index){
    if (textArea){
        return areas.add(textArea, index);
    }
    return false;
}

TextArea* FlowPanel::getTextArea(const string& id){
    return areas.get(id);
}

TextArea* FlowPanel::getTextArea(int index){
    return areas.get(index);
}

TextArea* FlowPanel::removeTextArea(const string& id){
    return areas.remove(id);
}

TextArea* FlowPanel::removeTextArea(int index){
    return areas.remove(index);
}

bool FlowPanel::overlaps(const FlowPanel &other) const {
    return this->dimensions.overlaps(other.dimensions);
}

void FlowPanel::draw(Display *display, Window win, GC gc) const {
    int X = dimensions.x + xgap;
    int Y = dimensions.y + ygap;
    int rowHeight = 0;

    for (int i = 0; i < areas.getSize(); i++){
        TextArea* textArea = areas.get(i);
        if (!textArea){
            continue;
        }
        int taWidth = textArea->getDimensions().width;
        int taHeight = textArea->getDimensions().height;

        if (X + taWidth + xgap > dimensions.x + dimensions.width){
            X = dimensions.x + xgap;
            Y += rowHeight + ygap;
            rowHeight = 0;
        }

        if (Y + taHeight > Y + dimensions.height){
            break;
        }

        textArea->draw(display, win, gc, X, Y);
        X += taWidth + xgap;
        rowHeight = std::max(rowHeight, taHeight);
    }   
}

void FlowPanel::print() const{
    cout << "FlowPanel : " << this -> id << endl;
    cout << "Position : " << this -> dimensions.x << ", " << this -> dimensions.y << endl;
    cout << "Size : " << this -> dimensions.width << ", " << this -> dimensions.height << endl;
    cout << "Num TextAreas : " << this -> areas.getSize() << endl;
}

void FlowPanel::printTextAreas() const {
    cout << "TextAreas : " << endl;
    for (int i = 0; i < areas.getSize(); i++) {
        TextArea* ta = areas.get(i);
        if (ta) {
            ta->print();  
    }
}
}
