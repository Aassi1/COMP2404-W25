#ifndef PANELARRAY_H
#define PANELARRAY_H

#include "Panel.h"
#include "FlowPanel.h"


class PanelArray {
    public:
        PanelArray();
        ~PanelArray();

        bool add(FlowPanel* panel);

    private: 
        FlowPanel** flowPanel;
        int size;
        int capacity;

};
#endif