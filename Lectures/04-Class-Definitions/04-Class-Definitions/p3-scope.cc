#include <iostream>
// #include "ext.cc"

using namespace std;

int x = 10;

// extern string name;



int main()
{
  //cout << name;
  cout << endl;
  cout<<"in main():  "<< x << endl;

  int x = 20;
  cout<<"in main():  "<< x << endl << endl;

  if (true) {
    x = 30;
    cout<<"in if:  "<< x << endl << endl;
  }

  {
    int x = 40;
    string name = "Elias";
    cout<<"in floating block, local:   "<< x << endl;
    cout<<"in floating block, global:  "<< ::x << endl << endl;
    cout<<"in floating block, local:   "<< name << endl;
    // cout<<"in floating block, global:   "<< ::name << endl;
  }

  //cout<<"in main(), global:   "<< name << endl;
  cout<<"in main(), local:   "<< x << endl;
  cout<<"in main(), global:  "<< ::x << endl << endl;

  ::x = 60;
  cout<<"in main(), local:   "<< x << endl;
  cout<<"in main(), global:  "<< ::x << endl << endl;

  return 0;
}

