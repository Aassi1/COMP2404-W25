#include <iostream>
using namespace std;

// Declaration
void power(int a, int b, int& c);

int main(){
    int x, y, z;
    cout << "Please enter 2 integers:" <<endl;
    cin >> x >> y;
    power(x,y,z);
    cout << x << " to the power of " << y << " is " << z << endl;
    return 0;
}