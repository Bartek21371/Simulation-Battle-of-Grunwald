#include <random>
#include <iostream>

#include <core/Battle.hpp>
#include <utils/Random.hpp>


/*
Battle::Battle() :   // to do
    weather(get_weather),
    randomEvents(get_randomEvents)
*/

// Main loop of battle ( attack and defend )

Battle::Battle(Army& HussarsArmy, Army& TeutonicArmy):
    Hussars(HussarsArmy),Teutonic(TeutonicArmy),round(1),winner({}),weather(){
}

// Start Battle loop
void Battle::start_Battle() {
    while (Hussars.count_AliveWarriors()>0 && Teutonic.count_AliveWarriors()>0) {
        do_Round();
    }

    if (Hussars.count_AliveWarriors()>0) {
        winner = "Hussars";
    }
    else {
        winner = "Teutonic";
    }
}


// Logic of doing round
void Battle::do_Round() {

    Warrior& hussars = Hussars.get_RandomAliveWarrior();

    Warrior& teutonic = Teutonic.get_RandomAliveWarrior();

    WeatherType weatherModifier = weather.get_WeatherType();

    if (Random::random_Int(0,1)==0) {
        hussars.attack_Enemy(teutonic, Hussars.get_MoraleModifier(), weatherModifier);
        if (teutonic.is_Alive()) {
            teutonic.attack_Enemy(hussars, Teutonic.get_MoraleModifier(), weatherModifier);
        }
    }
    else {
        teutonic.attack_Enemy(hussars, Teutonic.get_MoraleModifier(), weatherModifier);
        if (hussars.is_Alive()) {
            hussars.attack_Enemy(teutonic, Hussars.get_MoraleModifier(), weatherModifier);
        }
    }

    if (!hussars.is_Alive()) {
        Hussars.decrease_Morale(5);
        Teutonic.increase_Morale(5);
    }
    if (!teutonic.is_Alive()) {
        Teutonic.decrease_Morale(5);
        Hussars.increase_Morale(5);
    }

    round++;
}


// Getter
int Battle::get_Rounds() const {
    return round;
}

std::string Battle::get_Winner() const {
    return winner;
}

const Army& Battle::get_HussarsArmy() const {
    return Hussars;
}

const Army& Battle::get_TeutonicArmy() const {
    return Teutonic;
}

std::string Battle::get_Weather() const {
    return weather.to_String();
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
