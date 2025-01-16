#include "Student.h"
#include <iostream>

// Here we have the implementations of the class

// Here we are starting with a constructor (in this case it is a no argument constructor)
Student::Student(string name, string number, string major, float gpa){
    this->name = name;
    this->number = number;
    this->major = major;
    this->gpa = gpa;
}

Student::Student(){
    name = "";
    number = "";
    major = "";
    gpa = 0.0;
}

void Student::print(){
    cout<<name<<endl;
    cout<<number<<endl;
    cout<<major<<endl;
    cout<<gpa<<endl<<endl;
}
bool Student::isPassing(){
    return gpa >= 6.0;
}
    