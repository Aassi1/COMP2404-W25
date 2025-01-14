#include <iostream>
using namespace std;

int x = 10;  // file scope - global variable

int main ()
{
  int x = 8, size = 5, i = 0;
  // This x is 8 because in its scope it is defined as 8
  cout<<"x: "<<x<<endl; 

  while (i <= size) {
    int x = i;
    // x = i;
    ++i;
  }

  // This one is also 8
  cout<<"x: " << x << endl;  

  // Using the scope resolution operator ::, we can access global files from anywhere in the program
  // This is the value of the global variable x which is 10
  cout<<"x: " << ::x << endl;  

  return 0;
}

