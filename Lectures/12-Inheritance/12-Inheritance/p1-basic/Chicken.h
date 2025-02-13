#ifndef CHICKEN_H
#define CHICKEN_H

#include <string>
#include <iostream>
#include "Animal.h"

using namespace std;

class Chicken: public Animal {
    public:
        //eggcount
        Chicken(const string& name= "Charlie", int age =0, float lf = 0.0f, int ec = 0);
        ~Chicken();

        void print() const;

    private:
        int eggCount;

};



#endif