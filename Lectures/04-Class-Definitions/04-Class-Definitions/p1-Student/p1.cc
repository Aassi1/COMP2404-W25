#include <iostream>
#include <string>
#include "Student.h"
#define NUMSTUDENTS 3
using namespace std;


int main(){
    Student students[NUMSTUDENTS];


    string names[NUMSTUDENTS] = {"Joe", "Amy", "Barb"};
    string numbers[NUMSTUDENTS] = {"101111111", "101222222", "101333333"};
    string major[NUMSTUDENTS] = {"CS", "Math", "History"};
    float gpa[NUMSTUDENTS] = {10.0f, 11.2f, 5.9f};

    cout<<"Initializing all students:"<<endl;

    for (int i = 0; i < NUMSTUDENTS; ++i){
        students[i] = Student(names[i], numbers[i], major[i], gpa[i]);
    }

    cout<<"Printing all students:"<<endl;

    for (int i = 0; i < NUMSTUDENTS; ++i){
        students[i].print();
    }

    cout<<"Printing all passing students:"<<endl;

    for (int i = 0; i < NUMSTUDENTS; ++i){
        if (students[i].isPassing()){
            students[i].print();
        }
    }
}