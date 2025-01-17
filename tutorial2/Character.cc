#include "Character.h"
#include <iostream> 


Character::Character(const string& name, int maxHealth, int damage){
    this->name = name;
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->damage = damage;
}

void Character::takeDamage(int damage){
    currentHealth -= damage;
    if (currentHealth < 0){
        currentHealth= 0;
    }
}

int Character::strike(){
    return damage;
}

void Character::print(){
    cout << "Name : " << name << endl;
    cout << "Current  " << currentHealth << endl;
}

string Character::getName() const{
    return name;
}