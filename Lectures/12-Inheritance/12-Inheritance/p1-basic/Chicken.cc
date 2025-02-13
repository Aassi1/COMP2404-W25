#include "Chicken.h"
    
Chicken::Chicken(const string& name, int age, float lf, int ec): Animal(name, age, lf),  eggCount(ec){
    cout<<"-- in Chicken ctor --"<<getName()<<endl;
}

Chicken::~Chicken(){
    cout<<"-- in Chicken dtor --"<<endl;
}

void Chicken::print() const{
    Animal::print();
    cout<<" who is a chicken who lays "<<eggCount<<" eggs per day."<<endl;
}