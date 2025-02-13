#include <iostream>
using namespace std;

#include "Chicken.h"


int main()
{
  Animal  al("Al", 8);
  Chicken tracy("Tracy", 4, 12, 6, "chocolate");
  Chicken stanley("Stanley", 2, 12, 10);

  cout<<endl<<"ANIMALS:"<<endl;
  al.print();
  tracy.print();
  stanley.print();
  cout<<endl;


  return 0;
}

