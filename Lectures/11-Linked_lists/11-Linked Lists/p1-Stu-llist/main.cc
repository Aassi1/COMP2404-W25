#include <iostream>
using namespace std;

#include "List.h"
#include "Student.h"


int main()
{
 
  Student* stu = new Student("000000001", "Stu", "Comp sci", 11.0f);

  List comp2404;


  cout<<"Adding stu..."<<endl;
  comp2404.add(stu);
  cout<<"Printing students..."<<endl;
  comp2404.print();  
  cout<<"Adding students..."<<endl;
  comp2404.add(new Student("100333444", "Ellie", "Spanish", 11.5f));
  comp2404.add(new Student("100777888", "Harold", "Geography", 7.5f));
  comp2404.add(new Student("100555666", "Timmy", "Basket-weaving", 7.5f));
  comp2404.add(new Student("100778999", "Amy", "Math", 10.8f));
  comp2404.add(new Student("100333555", "Betty", "Physics", 11.8f));
  comp2404.add(new Student("100333766", "Charlie", "History", 10.5f));
  comp2404.add(new Student("100333768", "Dexter", "English", 8.5f));
  
  cout<<"Printing students..."<<endl;
  comp2404.print();

  string name  = "Harold";
  cout<<"Getting "<<name<<"..."<<endl;
  comp2404.get(name, &stu);

  if (stu!= NULL){
    stu->print();
  }else{
    cout<<name<<" not found"<<endl;
  }

  name  = "Bob";
  cout<<"Getting "<<name<<" (doesn't exist)..."<<endl;
  comp2404.get(name, &stu);

  if (stu!= NULL){
    stu->print();
  }else{
    cout<<name<<" not found"<<endl;
  }

  name  = "Bob";
  cout<<"Removing "<<name<<"..."<<endl;
  comp2404.remove(name, &stu);
  if (stu!= NULL){
    stu->print();
  }else{
    cout<<name<<" not found"<<endl;
  }

  name  = "Harold";
  cout<<"Removing "<<name<<"..."<<endl;
  comp2404.remove(name, &stu);
  if (stu!= NULL){
    stu->print();
  }else{
    cout<<name<<" not found"<<endl;
  }

  comp2404.print();

  name  = "Amy";
  cout<<"Removing "<<name<<"..."<<endl;
  comp2404.remove(name, &stu);
  if (stu!= NULL){
    stu->print();
  }else{
    cout<<name<<" not found"<<endl;
  }

  comp2404.print();

  name  = "Timmy";
  cout<<"Removing "<<name<<"..."<<endl;
  comp2404.remove(name, &stu);
  if (stu!= NULL){
    stu->print();
  }else{
    cout<<name<<" not found"<<endl;
  }

  comp2404.print();

  name  = "Stu";
  cout<<"Removing "<<name<<"..."<<endl;
  comp2404.remove(name, &stu);
  if (stu!= NULL){
    stu->print();
  }else{
    cout<<name<<" not found"<<endl;
  }

  comp2404.print();

  name  = "Drake";
  cout<<"Removing "<<name<<"..."<<endl;
  comp2404.remove(name, &stu);
  if (stu!= NULL){
    stu->print();
  }else{
    cout<<name<<" not found"<<endl;
  }

  comp2404.print();

  cout << "Remove up to Charlie"<<endl;
  comp2404.removeUpTo("Charlie");
  comp2404.print();
  cout << "Remove up to Zeek"<<endl;
  comp2404.removeUpTo("Zeek");
  comp2404.print();

  return 0;
}

