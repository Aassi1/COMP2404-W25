#include <iostream>
using namespace std;

#include "List.h"

List::List(){
    size = 0;
    elements = new Student*[MAX_ARR];
}

List::~List(){
    delete [] elements;
}

bool List::add(Student* s){
    if (size >= MAX_ARR)return false;

    for (int i = size; i > 0 ; --i){
        if (s->lessThan(*elements[i-1])){
            //keep making space by copying elements
            //one location to the right
            elements[i]=elements[i-1];
        }else{
            //we have found where s should go
            elements[i] = s;
            ++size;
            return true;
        }
    }

    //we went through every location, and s was less than 
    //all of them. Therefore s goes in location 0
    elements[0] = s;
    ++size;
    return true;
    
}


Student* List::get(string id){
    for (int i = 0; i < size; ++i){
        if (elements[i]->equals(id)){
            return elements[i];
        }
    }
    return NULL;
}

Student* List::get(int index){
    if (index < 0 || index >= size) return NULL;
    return elements[index];
}

Student* List::remove(string number){
    
    int index = 0;
    //we want to find the index of the element to remove
    while (!elements[index]->equals(number) && index < size){
        ++index;
    }

    return remove(index);

}

Student* List::remove(int index){

    //did we fall off the end of the List?
    if (index<0 || index >=size) return nullptr;

    //we have found what we wanted to remove,
    //assign the output value
    Student *stu = elements[index];

    //copy everything after index left one position
    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    --size;
    return stu;

}

void List::removeUpTo(string name, List& arr){
   int index = 0;
   while (index < size){
    if (!elements[index]->lessThan(name)){
        break;
    }
    arr.add(elements[index]);
    ++index;
   }

   int remove = index;

   while (index < size){
        elements[index - remove]= elements[index];
        ++index;
   }



}

void List::getHonourRoll(List& hr){
    for (int i = 0; i < size; ++i){
        if (elements[i]->honourRoll()){
            hr.add(elements[i]);
        }
    }
}

void List::print()
{
  cout << endl << endl << "Students:" << endl;
  for (int i=0; i<size; ++i)
    elements[i]->print();

  cout << endl;
}