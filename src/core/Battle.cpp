#include <random>
#include <memory>
#include <iostream>

#include <core/Battle.hpp>


Battle::Battle(const Army& hussarsArmy,
               const Army& teutonicArmy,
               const Weather& battleWeather) :
        Hussars(hussarsArmy),
        TeutonicKnights(teutonicArmy),
        round(0),
        weather(battleWeather) {}


void Battle::add_Random_Event(
    std::shared_ptr<RandomEvent> event) {

    randomEvents.push_back(event);
}




void Battle::apply_Weather() {

    weather.effect_on_Battle();
}


void Battle::activate_Random_Event() {

    if (randomEvents.empty()) {
        return;
    }

    static std::random_device rd;
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

        switch (BattleResult result = check_Winner()) {

            case BattleResult::NON: continue;

            case BattleResult::HUSSARS_WINS:
                break;

            case BattleResult::TEUTONIC_WINS:
                break;

            case BattleResult::DRAW:
                break;
        }
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

    bool hussarsAttackFirst = (round % 2 == 1);

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

    hussars.remove_The_Fallen();
    teutonicKnights.remove_The_Fallen();

    stats.update_Stats(hussars, teutonicKnights);

    notify_Observers();
}



