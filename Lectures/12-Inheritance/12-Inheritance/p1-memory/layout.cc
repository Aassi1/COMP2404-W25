#include <iostream>
using namespace std;

class Boat{
  public:
    Boat(int cap = 0): capacity(cap){}
    virtual void print();

  private:
    int capacity;

};

class Sailboat: Boat{


  int numsails;
  float speed;
  public:
    virtual void print();
};


int main()
{
  
  Sailboat b;
  return 0;
}

