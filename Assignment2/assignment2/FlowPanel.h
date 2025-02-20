#ifndef FLOWPANEL_H
#define FLOWPANEL_H

#include "TextArea.h"
#include "defs.h"
#include "TAArray.h"

#include <string>
using namespace std;

class FlowPanel {
    public :
        FlowPanel(int x, int y, int width, int height, string id, int xgap, int ygap);
        FlowPanel(Rectangle rectangle, string id, int xgap, int ygap);
        






    private :
        string id;
        Rectangle dimensions;
        int xgap, ygap;
        TAArray areas;

};
#endif