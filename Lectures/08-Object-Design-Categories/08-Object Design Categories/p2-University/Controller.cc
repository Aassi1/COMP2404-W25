
#include "Controller.h"
#include "University.h"
#include "View.h"
#include "Student.h"


void Controller::launch(){
    uni = new University("Carleton");
    view = new View;

    int choice = -1;

    init(*uni);

    while(choice!=0){
        view->mainMenu(choice);

        switch(choice){
            case 1: addStudent(); break;
            case 2: removeStudent(); break;
            case 3: removeUpTo(); break;
            case 4: printStudents(); break;
            case 5: printHonourRoll(); break;
        }
    }

    delete uni;
    delete view;

}

void Controller::init(University& uni){
    uni.addStudent("Bob", "1", 9.0f);
    uni.addStudent("Cindy", "2", 10.0f);
    uni.addStudent("Frank", "3", 7.0f);
    uni.addStudent("Lucas", "4", 12.0f);
    uni.addStudent("Barb", "5", 11.0f);
    uni.addStudent("Jen", "6", 4.0f);
    uni.addStudent("Craig", "7", 1.0f);
    
}

void Controller::addStudent(){
    string name, number;
    float gpa;
    view->getStudentInfo(name, number, gpa);
    uni->addStudent(name, number, gpa);

}

void Controller::removeStudent(){
    string name;
    view->getStudentName(name);
    if (uni->removeStudent(name)){
        cout<<"Student removed"<<endl;
    }else{
        cout<<"Student not found"<<endl;
    }
}

void Controller::printStudents(){
    List* list;
    uni->getStudents(&list);
    cout<<"Printing students"<<endl;
    view->printStudents(*list);
}

void Controller::removeUpTo(){
    
}

void Controller::printHonourRoll(){
   List hr;
   uni->getHonourRoll(hr);
   view->printStudents(hr);
}


		
