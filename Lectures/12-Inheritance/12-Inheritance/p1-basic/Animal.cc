#include <iostream>
using namespace std;
#include <string>

#include "Animal.h"


Animal::Animal(const char* n, int a, float lf)
    :  age(a), lifespan(lf)
{ 
  
  cout<<"-- Animal ctor: "<<name<<endl;
}

Animal::~Animal()
{ 
  cout<<"-- Animal dtor: "<<name<<endl;
}

string Animal::getName() const { return name; }

void Animal::print() const  
{
  cout<<"Animal:  "<<name<<", age "<<age<<", with lifespan "<< lifespan<<endl;
}

