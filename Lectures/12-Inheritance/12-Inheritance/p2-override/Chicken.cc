#include <iostream>
using namespace std;
#include <string>

#include "Chicken.h"


Chicken::Chicken(string n, int a, float lf, int ec)
    : Animal(n,a,lf), eggCount(ec)
{ 
  cout<<"-- Chicken ctor: "<<getName()<<endl;
}

Chicken::~Chicken()
{ 
  cout<<"-- Chicken dtor: "<<getName()<<endl;
}

void Chicken::forage(const string& f) const
{
  cout << "Chicken " << getName() << " forages for " << f << endl;
}

void Chicken::forage(int min) const
{
  Animal::forage(min);
}


void Chicken::print() const  
{
  Animal::print();
  cout<<" and I'm a chicken that can produce "<<eggCount<<" eggs daily"<<endl;
}

