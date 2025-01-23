#include <iostream>
using namespace std;

int memLeak();
void memLeak2(int* i1);

int main()
{ 
  // int* p1 = NULL;

  int p2 = memLeak();
  
  
  // memLeak2(p1);
 
  // delete p1;
  return 0;
}

int memLeak(){
  int* i1 = new int(87);
  cout<<"i1: "<<*i1<<endl;
  cout<<"Returning from memLeak"<<endl;
  return *i1;
}

void memLeak2(int* i1){
  i1 = new int(87);
  cout<<"i1: "<<*i1<<endl;
  cout<<"Returning from memLeak2"<<endl;
}
