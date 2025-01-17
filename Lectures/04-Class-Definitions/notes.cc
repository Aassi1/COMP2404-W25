/*
Classes

A class contains a header file that contains the class definition and a cpp file that contains the class implementation.
In the header file, it contains data member declarations as well a member function prototypes

In also contains a source file that contains the class implementation.

The access modifiers are defined in blocks, by default, everything is private.


Objects in memory
when we use the new keyword, the objects is allocated on the heap

The header file will contain all the declarations and the source file will contain the implementation

We have to use the scope resolution operator to access the member functions : 

void Student::print(){
    cout<<"Name: "<<name<<endl;
    cout<<"Id: "<<id<<endl;
}

Job of a constructor to initialize all data members
> There are a few ways to initialize data members
> We will start with the most conventional
> assignment operators
Constructor with no arguments – default constructor
> can be very important for things like arrays
> we decide if there is a default constructor
C++ classes can have multiple constructors
> cannot call “super” as with Java to make use of multiple constructors
> C++ can leverage other constructors, but uses a different syntax

---------------------------------
so that the compiler does not load up header files multiple times, we can use header guards

#ifndef STUDENT_H
#define STUDENT_H

the ifndef must have a corresponding endif and these are put in the header file,, refer to Student.h for the implementation of the header guards

We can allocate classes statically or dynamically. chcek programing example p2


 */