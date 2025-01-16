#include <iostream>
using namespace std;
#include <string>

#define MAX_SIZE  3

#include "Date.h"


int main()
{
  cout << endl;

  Date d1(2020, 9, 9);
  Date d2;

  

  cout << "Printing d1:"<< endl;
  d1.print();


  cout << endl  << "Printing d2:"<< endl;
  d2.print();


  // d2.setDate(2022, 10, 31);
  // cout << endl  << "Printing d2:"<< endl;
  // d2.print();
  // cout << endl;

  // Date dArray[MAX_SIZE];

  // cout << endl  << "Printing array of Date objects:"<< endl;

  // for (int i=0; i<MAX_SIZE; ++i)
  //   dArray[i].print();

  // dArray[0].setDate(1922, 2, 2);
  // dArray[1].setDate(1933, 3, 3);

  // cout << endl  << "Printing array of Date objects:"<< endl;
  // for (int i=0; i<MAX_SIZE; ++i)
  //   dArray[i].print();
  
  
  // Date* arr[MAX_SIZE];
  // arr[0] = &d1;
  // arr[1] = &d2;

  // cout << endl  << "Printing array of Date pointers:"<< endl;

  // for (int i=0; i<MAX_SIZE; ++i){
  //   // the last location is not initialized, and so we get a segmentation fault
  //   arr[i]->print();
  // }

  // cout << endl;
  return 0;
}
