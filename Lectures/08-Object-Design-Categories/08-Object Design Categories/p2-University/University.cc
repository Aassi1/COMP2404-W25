
#include "University.h"

University::University(string name){
    this->name = name;
}

University::~University(){
    
}


bool University::addStudent(string name, string number, float gpa){
    Student* newstudent= new Student(name, number, gpa);
    if(! students.add(newstudent)){
        delete newstudent;
        return false;
    }

    return true;
}

bool University::removeStudent(string number){
    Student* goner = students.remove(number);
    if (goner == nullptr) return false;
    delete goner;
    return true;

}

void University::removeUpTo(string number){
    
}


/*
* honours is a list that is passed in to be populated
* with honour roll students.
*/
void University::getHonourRoll(List& honours){
    students.getHonourRoll(honours);
}

void University::getStudents(List** students){
    *students = &(this->students);
}


void University::print() {
    cout<<"University: "<<name<<endl;
}

