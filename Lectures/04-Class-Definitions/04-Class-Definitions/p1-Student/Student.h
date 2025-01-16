// header guard
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;


class Student{
    public:
        Student(string name, string number, string major, float gpa);
        Student();
        
        void print();
        bool isPassing();

    private:
        string name;
        string number;
        string major;
        float gpa;
};

#endif