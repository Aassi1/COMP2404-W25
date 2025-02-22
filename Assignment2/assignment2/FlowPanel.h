#ifndef FLOWPANEL_H
#define FLOWPANEL_H

#include "TextArea.h"
#include "defs.h"
#include "TAArray.h"

#include <string>
using namespace std;

struct Rectangle {
    int x, y, width, height;
};

class FlowPanel {
    public :
        FlowPanel(int x, int y, int width, int height, string id, int xgap, int ygap);
        FlowPanel(Rectangle rectangle, string id, int xgap, int ygap);
        

        void print();
        void printTextArea();

    private :
        Rectangle dimensions;
        string id;
        int xgap, ygap;
        TAArray areas;

};
#endif