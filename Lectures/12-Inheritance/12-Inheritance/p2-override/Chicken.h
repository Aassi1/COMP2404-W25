#ifndef CHICKEN_H
#define CHICKEN_H

#include "Animal.h"

class Chicken : public Animal
{
  public:
    Chicken(string="Chicky", int=0, float=0, int=0);
    ~Chicken();
    void   print() const;

    void forage(const string&) const;
    void forage(int) const;

  private:
    int eggCount;
};

#endif
