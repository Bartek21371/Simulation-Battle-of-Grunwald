#include <random>
#include <iostream>

#include <core/Battle.hpp>
#include <utils/Random.hpp>
#include <events/CommanderDeath.hpp>
#include <events/AlliedHelp.hpp>
#include <events/PanicEvent.hpp>


// Main loop of battle ( attack and defend )

Battle::Battle(Army& HussarsArmy, Army& TeutonicArmy):
    Hussars(HussarsArmy),Teutonic(TeutonicArmy),round(1),winner(),weather(),stats(),eventsTriggered(0),maxEvents(3){

    randomEvents.push_back(std::make_unique<CommanderDeath>());

    randomEvents.push_back(std::make_unique<AlliedHelp>());

    randomEvents.push_back(std::make_unique<PanicEvent>());
}

// Start Battle loop
void Battle::start_Battle() {
    if (is_finished()) {
        do_Round();
        finishBattle();
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

        currentEvent = hussars.get_Type()+ " attacked "+teutonic.get_Type();
        hussars.attack_Enemy(teutonic, Hussars.get_MoraleModifier(), weatherModifier);

        damage_dealt -= teutonic.get_Health();
        stats.add_HussarsDamage(damage_dealt);

        if (teutonic.is_Alive()) {
            damage_dealt = hussars.get_Health();

            currentEvent = teutonic.get_Type()+ " counter-attacked "+hussars.get_Type();
            teutonic.attack_Enemy(hussars, Teutonic.get_MoraleModifier(), weatherModifier);

            damage_dealt -= hussars.get_Health();
            stats.add_TeutonicDamage(damage_dealt);
        }
    }
    else {
        damage_dealt = hussars.get_Health();

        currentEvent = teutonic.get_Type()+ " attacked "+hussars.get_Type();
        teutonic.attack_Enemy(hussars, Teutonic.get_MoraleModifier(), weatherModifier);

        damage_dealt -= hussars.get_Health();
        stats.add_TeutonicDamage(damage_dealt);

        if (hussars.is_Alive()) {
            damage_dealt = teutonic.get_Health();

            currentEvent = hussars.get_Type()+ " counter-attacked "+teutonic.get_Type();
            hussars.attack_Enemy(teutonic, Hussars.get_MoraleModifier(), weatherModifier);

            damage_dealt -= teutonic.get_Health();
            stats.add_HussarsDamage(damage_dealt);
        }
    }

    if (!hussars.is_Alive()) {
        Hussars.decrease_Morale(5);
        Teutonic.increase_Morale(5);

        stats.add_TeutonicKill();

        currentEvent = teutonic.get_Type() + " killed " + hussars.get_Type();
    }
    if (!teutonic.is_Alive()) {
        Teutonic.decrease_Morale(5);
        Hussars.increase_Morale(5);

        stats.add_HussarsKill();

        currentEvent = hussars.get_Type() + " killed " + teutonic.get_Type();

    }

    round++;

    if (round > 20 && eventsTriggered<maxEvents) {
        if (Random::random_Int(1,100)<=3) {
            triggerRandomEvent();
            eventsTriggered++;
        }
    }

    notify();
}

bool Battle::is_finished() const {
    return Hussars.count_AliveWarriors()==0 || Teutonic.count_AliveWarriors()==0;
}

void Battle::finishBattle() {
    if (Hussars.count_AliveWarriors()>0) {
        winner = "Hussars";
    }
    else {
        winner = "Teutonic";
    }
}

void Battle::notify() {
    for (BattleObserver* observer : observers) {
        observer->update(*this);
    }
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

const std::string& Battle::get_CurrentEvent() const {
    return currentEvent;
}

void Battle::triggerRandomEvent() {
    int id = Random::random_Int(0, static_cast<int>(randomEvents.size()) - 1);

    Army& targetArmy = Random::random_Int(0,1) ? Hussars : Teutonic;

    randomEvents[id]->apply(targetArmy);

    currentEvent = targetArmy.get_Name() + ": " + randomEvents[id]->getName();

    notify();
}
