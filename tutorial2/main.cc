#include <iostream>
#include "Character.h"
#include "battle.h"
using namespace std;


int main(){

    string name;
    int maxHealth, damage;

    cout << "Enter name for a fighter character: ";
    cin >> name;

    cout << "Enter maxHealth for a fighter character: ";
    cin >> maxHealth;

    cout << "Enter damage for a fighter character: ";  
    cin >> damage;

    Character fighter(name, maxHealth, damage);

    cout << "Enter name for an orc character: ";
    cin >> name;

    cout << "Enter maxHealth for an orc character: ";
    cin >> maxHealth;

    cout << "Enter damage for an orccharacter: ";  
    cin >> damage;

    Character orc(name, maxHealth, damage);

    fighter.print();
    orc.print();

    Gondor::fight(fighter, orc);
    fighter.print();
    orc.print();

    Mordor::fight(fighter,orc);
    fighter.print();
    orc.print();
}