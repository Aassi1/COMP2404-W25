#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using namespace std;

class Character{
    public:
         Character(const string&, int maxHealth, int damage);
         void takeDamage(int damage);
         int strike();
         void print();
         string getName() const;

    private:
        string name;
        int maxHealth;
        int currentHealth;
        int damage;

};
#endif