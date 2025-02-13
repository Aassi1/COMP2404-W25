#include <iostream>
#include <vector>
using namespace std;

class Stack1: public vector<int> {

  public:
    void push(int num){ push_back(num);}
    int pop(){
      int tmp = at(size()-1);
      pop_back();
      return tmp;
    }
    bool empty(){
      return vector<int>::empty();
    }


};


class Stack2{

  public:
    void push(int num){ myStuff.push_back(num);}
    int pop(){
      int tmp = myStuff.at(myStuff.size()-1);
      myStuff.pop_back();
      return tmp;
    }
    bool empty(){
      return myStuff.empty();
    }

    private:
      vector<int> myStuff;

};

class Stack3: private vector<int> {

  public:
    //void push(int num){ push_back(num);}
    using vector<int>::push_back;
    int pop(){
      int tmp = at(size()-1);
      pop_back();
      return tmp;
    }

    bool empty(){
      return vector<int>::empty();
    }
};



int main()
{
  Stack1 st1;
  Stack2 st2;
  Stack3 st3;

  cout << endl << "Pushing..." << endl;

  for (int i=0; i<10; ++i) {
    int num = (i+1) * 2;
    cout << num << " ";
    st3.push_back(num);
  }
  cout << endl;

  //cout<<"Using random access.."<<endl;

  //cout<<st3.at(3)<<endl;

  for (int i=0; i<10; ++i) {
    int num = st3.pop();
    cout << num << " ";
  }

  return 0;
}

