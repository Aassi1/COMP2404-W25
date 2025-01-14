#include <iostream>
using namespace std;

int main()
{
  int x, y;
  // Stream insertion operator
  cout << "Enter 2 numbers: ";
  // Stream extraction operator
  cin >> x >> y;

  cout << "You have output x : " << x << " and y : " << y << endl;
  
  return 0;
}

