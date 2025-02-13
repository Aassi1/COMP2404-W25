#ifndef STACKARRAYS_H   
#define STACKARRAYS_H

#include "defs.h"
#include "TextArea.h"
   

class StackArrays{
    public:
        StackArrays();
        ~StackArrays();

        TextArea* getObjectArray(){
            return textObject;
        }

        TextArea** getPointerArray(){
            return textPointers;
        };
        
        TextArea *getPointer(int index){
            return textPointers[index];
        }

        TextArea getReference(int index){
            return textObject[index];
        }

    void addTextArea(TextArea& textArea){  
    }

    private:
        TextArea textObject[MAX_ARRAY];
        TextArea* textPointers[MAX_ARRAY];
        int numOfTextObjects;

};
#endif