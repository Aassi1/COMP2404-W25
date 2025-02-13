#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H

#include "defs.h"
#include "TextArea.h"


class HeapArrays{
    public:
        HeapArrays();
        ~HeapArrays();
        
        TextArea *getObjectArray();
        TextArea **getPointerArray();
        
        TextArea *getPointer(int index);        
        TextArea& getReference(int index);

        void addTextArea(TextArea &textArea);
        
    private:
        TextArea *textObjects;
        TextArea **textPointers;
        int numOfTextObjects; 
};
#endif