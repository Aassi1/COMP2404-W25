#include <iostream>
using namespace std;
#include "battle.h"


namespace Gondor
{
    void fight(Character& fighter, Character& orc){
        int fighterDamage = fighter.strike() + 1;
        int orcDamage = orc.strike() -1;

        orc.takeDamage(fighterDamage);
        fighter.takeDamage(orcDamage);

        cout << fighter.getName() << " hits for " << fighterDamage << " damage." << endl;
        cout << orc.getName() << " hits for " << orcDamage << " damage." << endl;

    }


}

namespace Mordor{
    void fight(Character& fighter, Character& orc){
        int fighterDamage = fighter.strike()-1;
        int orcDamage = orc.strike() + 1;

        orc.takeDamage(fighterDamage);
        fighter.takeDamage(orcDamage);

        cout << fighter.getName() << " hits for " << fighterDamage << " damage." << endl;
        cout << orc.getName() << " hits for " << orcDamage << " damage." << endl;
    }

}