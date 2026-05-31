#include <events/RandomEvent.hpp>
#include <utils/Random.hpp>


RandomEvent::RandomEvent() :
    activationChance(5),
    commanderDeathHappened(false),
    alliedHelpHappened(false),
    panicHappened(false)
{}


void RandomEvent::activate(Army& army) {

    const int chanceRoll = Random::random_Int(1,100);

    if (chanceRoll > activationChance) {
        return;
    }

    int eventRoll = Random::random_Int(0,2);

    switch (eventRoll) {
        case 0:
            if (commanderDeathHappened) return;
            commanderDeath(army);
            commanderDeathHappened = true;
            return;

        case 1:
            if (alliedHelpHappened) return;
            alliedHelp(army);
            alliedHelpHappened = true;
            return;

        case 2:
            if (panicHappened) return;
            panic(army);
            panicHappened = true;
            return;
    }
}


void RandomEvent::commanderDeath(Army& army) {
    army.decrease_Morale(10);
}


void RandomEvent::alliedHelp(Army& army) {
    army.increase_Morale(10);
}


void RandomEvent::panic(Army& army) {
    army.decrease_Morale(10);
}

