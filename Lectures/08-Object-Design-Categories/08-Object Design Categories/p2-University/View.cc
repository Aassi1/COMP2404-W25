
#include "View.h"

void View::mainMenu(int& choice)
{
  int numOptions = 5;

  cout << endl;
  cout << "What would you like to do?"<< endl;
  cout << "  (1) Add Student" << endl;
  cout << "  (2) Remove Student" << endl;
  cout << "  (3) Remove up to student" << endl;
  cout << "  (4) Print all students" << endl;
  cout << "  (5) Print honour roll" <<endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::getStudentInfo(string& name, string& number, float& gpa){
    cout<<endl<<"Enter student name: ";
    cin >> name;
    cout<<endl<<"Enter student number: ";
    cin >> number;
    cout<<endl<<"Enter student gpa: ";
    cin >> gpa;
    cout<<endl;
}

void View::getStudentName(string& name){
    cout<<endl<<"Enter student name: ";
    cin >> name;
    cout<<endl;
}

void View::printStudents(List& students){
    students.print();
}

