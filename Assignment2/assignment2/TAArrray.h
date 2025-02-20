#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#include <string>

class TAArray {
    public:
        TAArray();
        ~TAArray();
        
        bool add(TextArea* ta);
        bool add(TextArea* ta, int index);
        TextArea* get(int index) const;           
        TextArea* get(std::string id) const;      
        TextArea* remove(int index);              
        TextArea* remove(std::string id);         
        int getSize() const;                      
        
    private:
        TextArea** areas;
        int size;
        int capacity;
};
#endif