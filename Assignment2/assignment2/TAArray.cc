#include "TAArray.h"

TAArray::TAArray(){
    this->areas = new TextArea *[10];
    this->size = 0;
    this->capacity = 10;
}
TAArray::~TAArray(){
    for (int i = 0; i < size; i++)
    {
        delete areas[i];
    }
    delete[] areas;
}

bool TAArray::add(TextArea* ta) {
    if (size >= capacity) {
        return false;
    }
    areas[size] = ta;
    size++;
    return true;
}

bool TAArray::add(TextArea* ta, int index) {
    if (size >= capacity || index < 0 || index > size) {
        return false;
    }
    
    for (int i = size; i > index; --i) {
        areas[i] = areas[i-1];
    }
    
    areas[index] = ta;
    size++;
    return true;
}
TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    return areas[index];
}

TextArea* TAArray::get(std::string id) const {
    for (int i = 0; i < size; ++i) {
        if (areas[i]->getId() == id) {
            return areas[i];
        }
    }
    return nullptr;
}

TextArea* TAArray::remove(int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    
    TextArea* removed = areas[index];
    
    for (int i = index; i < size - 1; ++i) {
        areas[i] = areas[i + 1];
    }
    size--;
    
    return removed;
}

TextArea* TAArray::remove(std::string id) {
    for (int i = 0; i < size; ++i) {
        if (areas[i]->getId() == id) {
            return remove(i);
        }
    }
    return nullptr;
}

int TAArray::getSize() const {
    return size;
}

int TAArray::getId() const{
    return area.getId();
}