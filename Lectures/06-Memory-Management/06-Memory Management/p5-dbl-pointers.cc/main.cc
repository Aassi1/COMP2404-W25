#include <iostream>
using namespace std;
#include <string>
#include "Date.h"
#include "Calendar.h"

int main()
{
  cout << "Making a Calendar and adding Dates..."<<endl;
  Calendar cal;
  // add some Dates
  cal.addDate(2022, 2, 25, "Happy February");
  cal.addDate(1999, 12, 31, "Y2K");
  cal.addDate(2022, 1, 29, "Cold out today");

  cout<<"Printing Dates: "<<endl;
  

  cal.print();

  cout<<endl<<"Make a copy of the calendar and print: "<<endl;

  Calendar cal2(cal);

  cal2.print();

  
  // Date* dptr;

  // cout<<endl<<"Getting date"<<endl;
  // if (cal.getDate(0, &dptr)){
  //   dptr->print();
  // }else{
  //   cout<<"Date not found"<<endl;
  // }
  


  return 0;
}
