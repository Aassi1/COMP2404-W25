Name : Assi Assi
Student ID : 101302142

## Files Included
- CuWindow.h/cc 
Creates and manages the window and its panels
- FlowPanel.h/cc
Creates and manages the flow panels
- TextArea.h/cc
Creates and manages the text areas
- TAArray.h/cc
Creates and manages the text area array
- PanelArray.h/cc
Creates and manages the panel array
- RGB.h/cc
Creates and manages the RGB values
- defs.h
Defines the constants
- Makefile
Makefile for the assignment

## How to compile

make


## How to run

./a2

Flow layout implementaion : 

1. TextAreas are arranged from left to right 
2. When a TextArea doesn't fit horizontally, it wraps to the next row
3. Each row's TextAreas are aligned at their tops
4. The vertical position of each new row is determined by the tallest TextArea in the previous row
5. If a TextArea doesn't fit vertically within the panel, it and all remaining TextAreas are not drawn

The layout respects the xgap and ygap parameters to maintain proper spacing between TextAreas and from the panel edges. When determining if a TextArea fits, the algorithm checks:
- If adding the TextArea would exceed the panel's width, it moves to the next row
- If adding the TextArea would exceed the panel's height, it stops drawing

This implementation ensures that TextAreas are properly arranged in a flowing manner while respecting the boundaries of the containing panel.

