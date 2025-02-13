#include <iostream>
using namespace std;
#include <string>

class Animal
{
  public:
    Animal(string n) : name(n) { }
    string name;
};

class Human : virtual public Animal
{
  public:
    Human(int f, string n) : numArms(f), Animal(n) { }
  private:
    int numArms;
};

class Horse : virtual public Animal
{
  public:
    Horse(int h, string n) : numLegs(h), Animal(n) { }
  private:
    int numLegs;
};

class Centaur : public Human, public Horse
{
  public:
    Centaur(int arms, int legs, string n) : Human(arms,n), Horse(legs,n), Animal(n) { }
};


int main()
{
  Centaur bane(2, 4, "Bane");

  cout << endl << "name: " << bane.name << endl;

  cout << endl << "Human name: " << bane.Human::name << endl;
  cout << "Horse name:  " << bane.Horse::name << endl;

  bane.Human::name = "Doris";
  cout << endl << "Human name: " << bane.Human::name << endl;
  cout << "Horse name:  " << bane.Horse::name << endl;

  return 0;
}
