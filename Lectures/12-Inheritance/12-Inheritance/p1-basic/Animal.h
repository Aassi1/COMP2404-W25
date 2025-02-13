#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal
{
  public:
    Animal(const char* name ="Al", int=0, float=0);
    ~Animal();
    string getName() const;
    void   print()   const;
    
  protected:
    float  lifespan;

  private:
    char* name;
    int    age;
    
};

#endif
