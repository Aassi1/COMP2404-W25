#include <iostream>
using namespace std;
#include <string>
#include "Date.h"
#include "Calendar.h"

#define MAX_SIZE  3

int main()
{

  cout << "Allocating on the stack:"<<endl;

  Date d1(2023, 1, 30);
  Date d2(2023, 2, 20);


  cout <<endl<< "Allocating on the heap:"<<endl;
  
  Date* d3;
  d3 = new Date(2023, 2, 2);



  cout <<endl<< "Deleting from the heap:"<<endl;

  delete d3;

  cout <<endl<< "Statically allocating a Calendar (which contains dynamic memory)"<<endl;

  Calendar cal;
  
  cal.addDate(2023, 6, 12, "Class");
  cal.addDate(2023, 6, 14, "Tutorial");
  cal.addDate(2023, 6, 10, "Midterm");
  

  cal.print();

  cout <<endl<<"Exiting main..."<<endl;

  
  return 0;
}
