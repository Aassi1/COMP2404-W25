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