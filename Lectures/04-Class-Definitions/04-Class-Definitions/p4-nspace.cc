#include <iostream>
using namespace std;
#include <string>

/*
Tracking employees of a video game store
*/

string manager = "Jesse James";

/*
 Unnamed namespace variables are global for this file only.
 Cannot be accessed by linking.
*/
namespace
{
  string manager = "Someone";
  string cashier = "William H. Bonney";
  string stock = "Pat Garrett";
}

// extern string manager;
// extern string cashier;
// extern string stock;

namespace Orleans
{
  string manager = "Wyatt Earp";
  string cashier = "Doc Holiday"; 
  string stock   = "Virgil Earp";

  void printEmployees();

  namespace DemoBooth
  {
    enum Consoles { XBOX=101, SWITCH, PLAYSTATION };
  }
}




int main()
{
  cout<<endl<<"Cashier from unnamed space:  "<< cashier <<endl<<endl;
  //cout<<"Manager from unnamed space:  "<<manager<<endl<<endl;
  cout<<"Original manager:  "<< ::manager <<endl<<endl;

  cout<<"From namespace Orleans:"<<endl;
  cout<<"  Manager:      "<< Orleans::manager <<endl;
  cout<<"  Cashier:      "<< Orleans::cashier   <<endl;
  cout<<"  Stock:        "<< Orleans::stock    <<endl;
  cout<<"  XBox:         "<< Orleans::DemoBooth::XBOX   <<endl;
  cout<<"  Switch:       "<< Orleans::DemoBooth::SWITCH      <<endl;
  cout<<"  Playstation:  "<< Orleans::DemoBooth::PLAYSTATION <<endl;

  Orleans::printEmployees();

  return 0;
}

//using namespace Orleans;

void Orleans::printEmployees()
{
  cout<<endl<<"Printing employees:"<<endl;
  cout<<"  Manager:      "<< manager <<endl;
  cout<<"  Cashier:      "<< cashier   <<endl;
  cout<<"  Stock:        "<< stock    <<endl;

  cout<<"  XBox:         "<< DemoBooth::XBOX   <<endl;
  cout<<"  Switch:       "<< DemoBooth::SWITCH      <<endl;
  cout<<"  Playstation:  "<< DemoBooth::PLAYSTATION <<endl;

  cout<<"  Old Manager: "<< ::manager  <<endl;
  cout<<"  Old Cashier: "<< ::cashier  <<endl;
  cout<<"  Old Stock:   "<< ::stock  <<endl<<endl;

}
