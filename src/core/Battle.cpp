#include <random>
#include <memory>
#include <iostream>

#include <core/Battle.hpp>

/*
Battle::Battle() :   // to do
    Hussars(get_Hussars),
    TeutonicKnights(get_TeutonicKnights),
    round(0),
    weather(get_weather),
    randomEvents(get_randomEvents)
{}
*/

// Main loop of battle ( attack and defend )

Battle::Battle(Army HussarsArmy, Army TeutonicArmy):
    Hussars(HussarsArmy),Teutonic(TeutonicArmy),round(0){
}

// Start Battle loop
void Battle::start_Battle() {
    while (Hussars.count_AliveWarriors()>0 && Teutonic.count_AliveWarriors()>0) {
        do_Round();
    }
}

// Logic of doing round
void Battle::do_Round() {
    Warrior& attacker = Hussars.get_FirstAliveWarrior();
    Warrior& defender = Teutonic.get_FirstAliveWarrior();
    attacker.attack_Enemy(defender);
    if (defender.is_Alive()) {
        defender.attack_Enemy(attacker);
    }
    round++;
}

// Getter
int Battle::get_Round() const {
    return round;
}

/*int Battle::random_Number(int min, int max) {

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> numberRange(min, max);

    return numberRange(gen);
}



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

/*  to do
BattleResult Battle::check_Winner() {

    bool hussarsAlive = !Hussars.get_Warriors().empty();

    bool teutonicAlive = !TeutonicKnights.get_Warriors().empty();

    if (hussarsAlive && !teutonicAlive) {
        return BattleResult::HUSSARS_WINS;
    }

    if (!hussarsAlive && teutonicAlive) {
        return BattleResult::TEUTONIC_WINS;
    }

    if (!hussarsAlive && !teutonicAlive) {
        return BattleResult::DRAW;
    }

    return BattleResult::NON;
}
*/

/*
void Battle::do_Round() {

    round++;

    apply_Weather();
    activate_Random_Event();

    std::vector<Warrior> hussarsWarriors = Hussars.get_Warriors();  // do usunięcia po zrobieniu konstrktorów army
    std::vector<Warrior> teutonicWarriors = TeutonicKnights.get_Warriors();

    if (hussarsWarriors.empty() || teutonicWarriors.empty()) return;

    const bool hussarsAttackFirst = (round % 2 == 1);

    int randomHussarsIndex = random_Number(0, hussarsWarriors.size() - 1);
    int randomTeutonicIndex = random_Number(0, teutonicWarriors.size() - 1);


    if (hussarsAttackFirst) {

        Warrior* attacker = &hussarsWarriors[randomHussarsIndex];
        Warrior* target = &teutonicWarriors[randomTeutonicIndex];

        if (attacker->is_Alive() && target->is_Alive()) {
            //attack
        }

    } else {

        Warrior* attacker = &teutonicWarriors[randomTeutonicIndex];
        Warrior* target = &hussarsWarriors[randomHussarsIndex];

        if (attacker->is_Alive() && target->is_Alive()) {
            //attack
        }
    }

    Hussars.remove_The_Fallen();
    TeutonicKnights.remove_The_Fallen();

    stats.update_Stats(Hussars, TeutonicKnights);

}
*/


