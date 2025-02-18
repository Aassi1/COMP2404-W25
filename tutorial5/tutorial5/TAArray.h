#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"


class TAArray{
    public:
        TAArray();
        ~TAArray();

        bool add(TextArea &tas);
        bool add(TextArea &ta, int index);

    private:
        TextArea **areas;
        int size;
        int capacity;
        

};
#endif