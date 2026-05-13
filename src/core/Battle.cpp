#include <random>
#include <memory>
#include <iostream>

#include <core/Battle.hpp>


Battle::Battle() :   //gettery do zrobienia
    Hussars(get_Hussars),
    TeutonicKnights(get_TeutonicKnights),
    round(0),
    weather(get_weather),
    randomEvents(get_randomEvents)
{}



void Battle::apply_Weather() {

    weather.effect_on_Battle();
}



void Battle::activate_Random_Event() {

    if (randomEvents.empty()) {
        return;
    }

    static std::random_device rd;      //random number generator
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> eventDist(0, randomEvents.size() - 1);
    std::uniform_int_distribution<> armyDist(0, 1);

    int eventIndex = eventDist(gen);

    std::vector<Warrior*>& targetArmy =
        (armyDist(gen) == 0)
        ? hussars
        : teutonicKnights;

    randomEvents[eventIndex]->activate(targetArmy);
}



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



void Battle::start_Battle() {

    while (true) {

        do_Round();

        if (check_Winner() != BattleResult::NON) return;

    }
}



void Battle::do_Round() {

    round++;

    apply_Weather();
    activate_Random_Event();

    auto& hussarsWarriors = Hussars.get_Warriors();
    auto& teutonicWarriors = TeutonicKnights.get_Warriors();

    if (hussarsWarriors.empty() || teutonicWarriors.empty()) return;

    static std::random_device rd;
    static std::mt19937 gen(rd());

    const bool hussarsAttackFirst = (round % 2 == 1);

    std::uniform_int_distribution<> distH(0, hussarsWarriors.size() - 1);
    std::uniform_int_distribution<> distT(0, teutonicWarriors.size() - 1);

    if (hussarsAttackFirst) {

        Warrior* attacker = hussarsWarriors[distH(gen)];
        Warrior* target = teutonicWarriors[distT(gen)];

        if (attacker->is_Alive() && target->is_Alive()) {
            attacker->attack_Enemy(target);
        }

    } else {

        Warrior* attacker = teutonicWarriors[distT(gen)];
        Warrior* target = hussarsWarriors[distH(gen)];

        if (attacker->is_Alive() && target->is_Alive()) {
            attacker->attack_Enemy(target);
        }
    }

    Hussars.remove_The_Fallen();
    TeutonicKnights.remove_The_Fallen();

    stats.update_Stats(Hussars, TeutonicKnights);

}



