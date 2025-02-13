#include "HeapArrays.h"
#include "defs.h"


HeapArrays::HeapArrays(){
    numOfTextObjects = 0;
    textObjects = new TextArea[MAX_ARRAY];
    textPointers = new TextArea *[MAX_ARRAY];
}

TextArea *HeapArrays::getObjectArray(){
    return textObjects;
};

TextArea **HeapArrays::getPointerArray(){
    return textPointers;
}

TextArea *HeapArrays::getPointer(int index){
    return textPointers[index];
}

TextArea& HeapArrays::getReference(int index) {
    return textObjects[index];
}

void HeapArrays::addTextArea(TextArea &textArea) {
    if (numOfTextObjects >= MAX_ARRAY) {
        return;
    }
    textObjects[numOfTextObjects] = textArea;
    textPointers[numOfTextObjects] = new TextArea(textArea);
    numOfTextObjects++;
}
HeapArrays::~HeapArrays() {
    for (int i = 0; i < numOfTextObjects; ++i) {
        delete textPointers[i];
    }
    delete[] textObjects;
    delete[] textPointers;
}