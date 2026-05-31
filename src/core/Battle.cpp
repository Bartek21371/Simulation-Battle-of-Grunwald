#include <random>
#include <iostream>

#include <core/Battle.hpp>
#include <utils/Random.hpp>


/*
    todo
    randomEvents(get_randomEvents)
    add helper function for calc damage_dealt>??>?>?

    maybe?:"""::::
        bool hussarsFirst = Random::random_Int(0,1) == 0;

        if (hussarsFirst)
        {
            ...
        }
        else
        {
            ...
        }


        Maybe there is problem with cost of going through vector of warriors, big armies=big problem?
        while (Hussars.count_AliveWarriors()>0 &&
               Teutonic.count_AliveWarriors()>0)
*/



// Main loop of battle ( attack and defend )

Battle::Battle(Army& HussarsArmy, Army& TeutonicArmy):
    Hussars(HussarsArmy),Teutonic(TeutonicArmy),round(1),winner(),weather(),stats(){
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

    Warrior& hussars(Hussars.get_RandomAliveWarrior());

    Warrior& teutonic(Teutonic.get_RandomAliveWarrior());

    WeatherType weatherModifier(weather.get_WeatherType());

    double damage_dealt{};

    if (Random::random_Int(0,1)==0) {
        damage_dealt = teutonic.get_Health();

        hussars.attack_Enemy(teutonic, Hussars.get_MoraleModifier(), weatherModifier);

        damage_dealt -= teutonic.get_Health();
        stats.add_HussarsDamage(damage_dealt);

        if (teutonic.is_Alive()) {
            damage_dealt = hussars.get_Health();

            teutonic.attack_Enemy(hussars, Teutonic.get_MoraleModifier(), weatherModifier);

            damage_dealt -= hussars.get_Health();
            stats.add_TeutonicDamage(damage_dealt);
        }
    }
    else {
        damage_dealt = hussars.get_Health();

        teutonic.attack_Enemy(hussars, Teutonic.get_MoraleModifier(), weatherModifier);

        damage_dealt -= hussars.get_Health();
        stats.add_TeutonicDamage(damage_dealt);

        if (hussars.is_Alive()) {
            damage_dealt = teutonic.get_Health();

            hussars.attack_Enemy(teutonic, Hussars.get_MoraleModifier(), weatherModifier);

            damage_dealt -= teutonic.get_Health();
            stats.add_HussarsDamage(damage_dealt);
        }
    }

    if (!hussars.is_Alive()) {
        Hussars.decrease_Morale(5);
        Teutonic.increase_Morale(5);

        stats.add_TeutonicKill();
    }
    if (!teutonic.is_Alive()) {
        Teutonic.decrease_Morale(5);
        Hussars.increase_Morale(5);

        stats.add_HussarsKill();
    }

    round++;
    notify();
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

const BattleStats& Battle::get_Stats() const {
    return stats;
}

void Battle::attach(BattleObserver* observer) {
    observers.push_back(observer);
}

void Battle::notify() {
    for (BattleObserver* observer : observers) {
        observer->update();
    }
}


/*
void Battle::activate_Random_Event() {

    if (randomEvents.empty()) {
        return;
    }

    int eventIndex = random_Number(0, randomEvents.size() - 1);
    int armyIndex = random_Number(0, 1);

    randomEvents[eventIndex]->activate(armyIndex);
}
*/
