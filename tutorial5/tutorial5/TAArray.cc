#include "TAArray.h"

TAArray::TAArray(){
    this->areas = new TextArea *[10];
    this->size = 0;
    this->capacity = 10;
}
TAArray::~TAArray(){
    for (int i = 0; i < size; i++)
    {
        delete this->areas[i];
    }
}
bool TAArray::add(TextArea &ta){
    if (size == capacity){
        return false;
    }
    areas[size] = new TextArea(ta);
    size++;
    return true;
}

bool TAArray::add(TextArea &ta, int index){
    if (size >= capacity || index < 0 || index > size) {
        return false;  
    }
    
    for (int i = size; i > index; --i) {
        areas[i] = areas[i-1];
    }
    
    areas[index] = new TextArea(ta);
    size++;
    return true;
}