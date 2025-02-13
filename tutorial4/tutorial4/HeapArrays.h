#ifndef HEAPARRAYS.h
#define HEAPARRAYS_H

#include "defs.h"
#include "TextArea.h"


class HeapArrays{
    public:
        HeapArrays();
        ~HeapArrays();
        
        TextArea *getTextObjects();
        TextArea **getTextPointers();
        
        TextArea *getPointer(int index);        
        TextArea getReference(int index);

        void addTextArea(TextArea &textArea);
        
    private:
        TextArea *textObjects;
        TextArea **textPointers;
        int numOfTextObjects; 
};
#endif