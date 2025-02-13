#include <iostream>
using namespace std;

#include "Chicken.h"


int main()
{
  Animal  al("Al", 8);
  Chicken chicky("Chicky", 4, 12, 6);

  cout<<endl<<"ANIMALS:"<<endl;
  al.print();
  chicky.print();
  cout<<endl;

  cout<<endl<<"Animals at feed time: "<<endl;
  al.forage(20);
  al.forage(0.5f);


  chicky.forage("worms");

  chicky.forage(20);
  chicky.Animal::forage(0.5f);

  cout<<endl;


  return 0;
}

