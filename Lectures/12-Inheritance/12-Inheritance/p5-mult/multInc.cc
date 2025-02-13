#include <iostream>
using namespace std;
#include <string>

class Animal{
  public:
    Animal(const string& n):name(n){}
    string name;
};

class Human:  public Animal{
  public:
    Human(int numArms, const string& name): numArms(numArms), Animal(name){}

  private:
    int numArms;
};

class Horse:  public Animal{
  public:
    Horse(int numLegs, const string& name): numLegs(numLegs), Animal(name){}

  private:
    int numLegs;
};

class Centaur: public Horse, public Human{
  public:
    Centaur(int numArms, int numLegs, const string& n): Horse(numLegs, n), Human(numArms, n){}
};

int main()
{
  Animal joe("Joe");

  Human bob(2, "Bob");

  Horse phil(4,"Phil");

  Centaur Centaur(2,4,"Mr Centaur");

  cout<<"names of our animals: "<<endl;

  cout<<joe.name<<endl;
  cout<<bob.name<<endl;
  cout<<phil.name<<endl;

  cout<<"Both Centaur names:"<<endl;
  cout<<Centaur.Horse::name<<endl;
  cout<<Centaur.Human::name<<endl;

  cout<<"Changing Human name of Centaur"<<endl<<endl;
  Centaur.Human::name="Joe";
  cout<<"Both Centaur names:"<<endl;
  cout<<Centaur.Horse::name<<endl;
  cout<<Centaur.Human::name<<endl;

  
  return 0;
}
