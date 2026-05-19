#include <random>
#include <iostream>

#include <core/Battle.hpp>


/*
Battle::Battle() :   // to do
    weather(get_weather),
    randomEvents(get_randomEvents)
*/

// Main loop of battle ( attack and defend )

Battle::Battle(Army& HussarsArmy, Army& TeutonicArmy):
    Hussars(HussarsArmy),Teutonic(TeutonicArmy),round(1){
}

// Start Battle loop
void Battle::start_Battle() {
    while (Hussars.count_AliveWarriors()>0 && Teutonic.count_AliveWarriors()>0) {
        do_Round();
        std::cout<<"--------Next round--------"<<"\n";
    }

    if (Hussars.count_AliveWarriors()>0) {
        std::cout<<"Hussars wins"<<"\n";
    }
    else {
        std::cout<<"Teutonic wins"<<"\n";
    }
}


// Logic of doing round
void Battle::do_Round() {
    std::cout<<"Hussars alive count: "<<Hussars.count_AliveWarriors()<<"\n";
    std::cout<<"Teutonic alive count: "<<Teutonic.count_AliveWarriors()<<"\n";
    std::cout<<"-------------------------------"<<"\n";
    std::cout<<"Round: "<<round<<"\n";

    Warrior& hussars = Hussars.get_RandomAliveWarrior();
    std::cout<<"Hussars hp: "<<hussars.get_Health()<<"\n";
    std::cout<<"Hussars attack: "<<hussars.get_Attack()<<"\n";

    Warrior& teutonic = Teutonic.get_RandomAliveWarrior();
    std::cout<<"Teutonic hp: "<<teutonic.get_Health()<<"\n";
    std::cout<<"Teutonic attack: "<<teutonic.get_Attack()<<"\n";

    if (random_Number(0,1)==0) {
        hussars.attack_Enemy(teutonic);
        if (teutonic.is_Alive()) {
            teutonic.attack_Enemy(hussars);
        }
    }
    else {
        teutonic.attack_Enemy(hussars);
        if (hussars.is_Alive()) {
            hussars.attack_Enemy(teutonic);
        }
    }
                                                            //// RANDOM WARRIOR SELECT TO FIGHT NOT ONLY WARRIOR.ALIVE[0]
    std::cout<<"Result after round: "<<round<<"\n";
    std::cout<<"Hussars hp: "<<hussars.get_Health()<<"\n";
    std::cout<<"Teutonic hp: "<<teutonic.get_Health()<<"\n";

    round++;
}


// Getter
int Battle::get_Round() const {
    return round;
}


// Helper function for random choice of hussars and teutonic in do_Round
int Battle::random_Number(int min, int max) {

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> numberRange(min, max);

    return numberRange(gen);
}




/*

void Battle::apply_Weather() {
    weather.effect_on_Battle();
}

void Battle::activate_Random_Event() {

    if (randomEvents.empty()) {
        return;
    }

    int eventIndex = random_Number(0, randomEvents.size() - 1);
    int armyIndex = random_Number(0, 1);

    randomEvents[eventIndex]->activate(armyIndex);
}
*/
