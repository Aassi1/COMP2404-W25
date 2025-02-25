#ifndef PANELARRAY_H
#define PANELARRAY_H

#include "FlowPanel.h"


class PanelArray {
    public:
        PanelArray();
        ~PanelArray();

        bool add(FlowPanel* panel);
        FlowPanel* get(int index);
        int getSize() const;

    private: 
        FlowPanel** flowPanel;
        int size;
        int capacity;

};
#endif