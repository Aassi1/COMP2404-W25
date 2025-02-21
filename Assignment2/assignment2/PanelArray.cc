#include "PanelArray.h"


// PanelArray::

PanelArray::~PanelArray(){
    delete[] flowPanel;
}

bool PanelArray::add(FlowPanel* panel){

    if (size >= capacity ){
        FlowPanel** newArray = new FlowPanel*[capacity * 2];
        for (int i = 0; i < size; ++i) {
            newArray[i] = flowPanel[i];
        }
        delete[] flowPanel;
        flowPanel = newArray;
        capacity *= 2;
    }
    flowPanel[size] = panel;
    size++;
    return true;
}