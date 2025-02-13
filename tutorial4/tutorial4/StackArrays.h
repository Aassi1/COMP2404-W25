#ifndef STACKARRAYS_H   
#define STACKARRAYS_H

#include "defs.h"
#include "TextArea.h"
   

class StackArrays{
    public:
        StackArrays();
        ~StackArrays();

        TextArea* getObjectArray();
        TextArea** getPointerArray();
        
        TextArea *getPointer(int index);        
        TextArea& getReference(int index);

        void addTextArea(TextArea& textArea);

    private:
        TextArea textObject[MAX_ARRAY];        
        TextArea* textPointers[MAX_ARRAY];     
        int numOfTextObjects;

};
#endif