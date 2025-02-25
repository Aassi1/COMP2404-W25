#include "PanelArray.h"

PanelArray::PanelArray() {
    flowPanel = new FlowPanel*[10];
    size = 0;
    capacity = 10;
}

PanelArray::~PanelArray() {
    delete[] flowPanel;
}

bool PanelArray::add(FlowPanel* panel) {
    if (size >= capacity) return false;
    flowPanel[size++] = panel;
    return true;
}

FlowPanel* PanelArray::get(int index) const{
    if (index < 0 || index >= size) return nullptr;
    return flowPanel[index];
}

int PanelArray::getSize() const {
    return size;
}

FlowPanel* PanelArray::remove(int index) {
    if (index < 0 || index >= size) return nullptr;
    FlowPanel* panel = flowPanel[index];
    for (int i = index; i < size - 1; i++) {
        flowPanel[i] = flowPanel[i + 1];
    }
    size--;
    return panel;
}