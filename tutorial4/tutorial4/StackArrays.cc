#include "StackArrays.h"
#include "TextArea.h"
#include "StackArrays.h"
#include <iostream>

using namespace std;

StackArrays::StackArrays(){
    numOfTextObjects = 0;
}
TextArea* StackArrays::getObjectArray(){
    return textObject;
}

TextArea **StackArrays::getPointerArray(){
    return textPointers;
}

TextArea *StackArrays::getPointer(int index){
    return textPointers[index];
}

TextArea &StackArrays::getReference(int index){
    return textObject[index];
}

void StackArrays::addTextArea(TextArea& textArea){
    if (numOfTextObjects >= MAX_ARRAY){
        cout << "Array is full" << endl;
    };
    textObject[numOfTextObjects] = textArea;
    textPointers[numOfTextObjects] = new TextArea(textArea);
    numOfTextObjects++;
}

StackArrays::~StackArrays() {
    for (int i = 0; i < numOfTextObjects; ++i) {
        delete textPointers[i];
    }
}