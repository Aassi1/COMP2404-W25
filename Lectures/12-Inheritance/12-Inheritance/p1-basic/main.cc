#include <iostream>
using namespace std;

#include "Animal.h"
#include "Chicken.h"


int main()
{
  Animal  alex("Alex", 8);

  Chicken charlie("Bob", 120, 200.0f, 10);

  cout<<endl<<"ANIMALS:"<<endl;

  alex.print();
  charlie.print();

  cout << endl;

  return 0;
}

