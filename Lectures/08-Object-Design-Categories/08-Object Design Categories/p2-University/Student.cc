
#include "Student.h"

Student::Student(string name, string num, float g){
    this->name = name;
    number = num;
    gpa = g;
}

Student::Student(Student& student){
    name = student.name;
    number = student.number;
    gpa = student.gpa;
}


bool Student::honourRoll(){
    return gpa >= 10.0f;
}

bool Student::lessThan(Student& stu){
    return name < stu.name;
}

bool Student::lessThan(string name){
    return this->name < name;
}

bool Student::equals(string name){
    return this->name == name;
}

void Student::print(){
    cout<<endl;
    cout<<"Student name  : "<<name<<endl;
    cout<<"Student number: "<<number<<endl;
    cout<<"Student GPA   : "<<fixed<<setprecision(1)<<gpa<<endl;

}