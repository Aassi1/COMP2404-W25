#ifndef FLOWPANEL_H
#define FLOWPANEL_H

#include "TextArea.h"
#include "TAArray.h"
#include "defs.h"
#include <string>

using namespace std;

// struct Rectangle {
//     int x, y, width, height;
// };

class FlowPanel {
    public :
        FlowPanel(int x, int y, int width, int height, string id, int xgap, int ygap);
        FlowPanel(Rectangle rectangle, string id, int xgap, int ygap);


        void print() const;
        void printTextArea();

    private :
        string id;
        Rectangle dimensions;
        int xgap, ygap;
        TAArray areas;

};
#endif

// #ifndef FLOWPANEL_H
// #define FLOWPANEL_H

// #include "defs.h"
// #include "TextArea.h"
// #include "TAArray.h"
// #include <string>


// class FlowPanel {
//     public:
//         // Constructors
//         FlowPanel(int x, int y, int width, int height, std::string id, int xgap = 10, int ygap = 10);
//         FlowPanel(Rectangle rectangle, std::string id, int xgap = 10, int ygap = 10);
//         FlowPanel(const FlowPanel& other); // Copy constructor

//         // Destructor
//         ~FlowPanel();

//         // Add a TextArea to the FlowPanel (transfers ownership)
//         void addTextArea(TextArea* textArea);

//         // Get a TextArea by index (does not transfer ownership)
//         TextArea* getTextArea(int index) const;

//         // Remove a TextArea by index (transfers ownership to the caller)
//         TextArea* removeTextArea(int index);

//         // Print functions
//         void print() const;
//         void printTextArea() const;

//     private:
//         std::string id;          // Unique ID of the FlowPanel
//         Rectangle dimensions;    // Position and size of the FlowPanel
//         int xgap, ygap;          // Gaps between TextAreas
//         TAArray areas;           // Array to store TextAreas
// };

// #endif