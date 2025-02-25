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
        FlowPanel* get(int index) const;
        FlowPanel* remove(int index);

    private: 
        FlowPanel** flowPanel;
        int size;
        int capacity;

};
#endif