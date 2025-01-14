/*
We are now talking about blocks 

In this example :

#include <iostream>
int x = 8;
for (int i = 0; i < 10; i++){
int x = i;
}
cout<<x<<endl;
, the value of x is 8, this is because the scope of x is limited to the for loop.
When we go into the for loop, we declare a new variable x. The new variable x gets left in the loop
and we get out of the loop. In essence, the value that is in the for loop is lost and overrriden by the value
declared at the top of the program.

Another example : 

int x = 8;
for (int i = 0; i < 10; i++){
x = i;
}
{
int x = 10;
cout<<x<<endl;
}
cout<<x<<endl;

Here we have a random block that is initialized randomly. Once we exit the block, the value of x remains 8 because the values of x that
have been defined are specific to the block itself.

reffer to p3.blk.cc for the example done after this

To learn more about pass by refferences vs pass by values, consult p5-parr.cc

If we pass an object by value, a copy of that object will be made into the function.
*/
