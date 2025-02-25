#include "FlowPanel.h"
#include "TextArea.h"
#include "X11/Xlib.h"
#include "defs.h"
#include <string>


FlowPanel::FlowPanel(int x, int y, int width, int height, string id, int xgap, int ygap) {
    this->dimensions.x = x;
    this->dimensions.y = y;
    this->dimensions.width = width;
    this->dimensions.height = height;
    this->id = id;
    this->xgap = xgap;
    this->ygap = ygap;
}

FlowPanel::FlowPanel(Rectangle rectangle, string id, int xgap , int ygap ) {
    this->dimensions = rectangle;
    this->id = id;
    this->xgap = xgap;
    this->ygap = ygap;
}

FlowPanel::FlowPanel(FlowPanel& other) {
    this->dimensions = other.dimensions;
    this->id = other.id;
    this->xgap = other.xgap;
    this->ygap = other.ygap;
    // Deep copy TextAreas
    for (int i = 0; i < other.areas.getSize(); i++) {
        TextArea* ta = other.areas.get(i);
        if (ta) {
            this->areas.add(new TextArea(*ta));
        }
    }
}

FlowPanel::~FlowPanel() {
}


// bool FlowPanel::addTextArea(TextArea* ta) {
//     if (ta) {
//         Rectangle taDim = ta->getDimensions();
//         // Check if the TextArea fits within the panel's dimensions
//         if (taDim.width <= dimensions.width && taDim.height <= dimensions.height) {
//             return areas.add(ta);
//         }
//     }
//     return false;
// }


// bool FlowPanel::addTextArea(TextArea* ta, int index) {
//     if (ta) {
//         Rectangle taDim = ta->getDimensions();
//         // Check if the TextArea fits within the panel's dimensions
//         if (taDim.width <= dimensions.width && taDim.height <= dimensions.height) {
//             return areas.add(ta, index);
//         }
//     }
//     return false;
// }

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

bool FlowPanel::overlaps(FlowPanel &other) const {
    return this->dimensions.overlaps(other.dimensions);
}

// void FlowPanel::draw(Display *display, Window win, GC gc) {
//     int currentX = dimensions.x + xgap;
//     int currentY = dimensions.y + ygap;
//     int rowHeight = 0;
    
//     for (int i = 0; i < areas.getSize(); i++) {
//         TextArea* current = areas.get(i);
//         if (!current) continue;  
        
//         Rectangle taDim = current->getDimensions();
        
//         if ((currentX + taDim.width) > (dimensions.x + dimensions.width - xgap)) {
            
//             currentX = dimensions.x + xgap;  
//             currentY += rowHeight + ygap;  
//             rowHeight = 0;  
//         }
        
//         if ((currentY + taDim.height) > (dimensions.y + dimensions.height - ygap)) {
            
//             break;
//         }
        
//         current->draw(display, win, gc, currentX, currentY);
        
//         currentX += taDim.width + xgap;
//         rowHeight = std::max(rowHeight, taDim.height);
//     }
// }

void FlowPanel::draw(Display *display, Window win, GC gc){
    draw(display, win, gc, this->dimensions.x, this->dimensions.y);
}

void FlowPanel::draw(Display *display, Window win, GC gc, int x, int y){
    int X = x + xgap;
    int Y = y + ygap;
    int rowHeight = 0;

    for (int i = 0; i < areas.getSize(); i++){
        TextArea* ta = areas.get(i);
        if (!ta){
            continue;
        }
        int taWidth = ta->getDimensions().width;
        int taHeight = ta->getDimensions().height;

        if (X + taWidth + xgap > x + dimensions.width){
            X = x + xgap;
            Y += rowHeight + ygap;
            rowHeight = 0;
        }

        if (Y + taHeight > Y + dimensions.height){
            break;
        }

        ta->draw(display, win, gc, X, Y);
        X += taWidth + xgap;
        rowHeight = std::max(rowHeight, taHeight);
    }   
}


// Prints information about this FlowPanel
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
