#include "FlowPanel.h"
#include "TextArea.h"




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



