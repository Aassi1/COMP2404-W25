#include <iostream>
using namespace std;

int x = 10;  // file scope - global variable

int main ()
{
  int x = 8, size = 5, i = 0;

  cout<<"x: "<<x<<endl; 

  while (i <= size) {
    int x = i;
    // x = i;
    ++i;
  }

  cout<<"x: " << x << endl;  

  cout<<"x: " << ::x << endl;  

  return 0;
}

