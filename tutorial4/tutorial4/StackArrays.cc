#include "StackArrays.h"
#include "TextArea.h"

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

TextArea StackArrays::getReference(int index){
    return textObject[index];
}

void StackArrays::addTextArea(TextArea& textArea){
    
}