#include <iostream>
#include <string>
#include <config/ConfigLoader.hpp>
#include <core/Battle.hpp>

// Battle loop

void battle() {
    std::vector<FractionConfig> config = ConfigLoader::LoadFromFile("../assets/configs/testfile_someinfected.csv",false);

    int battleNumber{1};

    for (size_t i = 0; i < config.size()-1; i+=2) {
        try {
            std::cout<<"========================"<<"\n";
            std::cout<<"Battle "<<battleNumber<<"\n";
            std::cout<<config[i].fraction<<" vs "<<config[i+1].fraction<<"\n";
            std::cout<<"========================"<<"\n";

            Army Hussars = Army(config[i]);
            Army Teutonic = Army(config[i + 1]);

            Battle battle = Battle(Hussars, Teutonic);

            battle.start_Battle();

            std::cout<<"Winner: "<<battle.get_Winner()<<"\n";
            std::cout<<"Rounds: "<<battle.get_Rounds()<<"\n";
            std::cout<<"Alive "<<config[i].fraction<<":"<<battle.get_HussarsArmy().count_AliveWarriors()<<"\n";
            std::cout<<"Alive "<<config[i+1].fraction<<":"<<battle.get_TeutonicArmy().count_AliveWarriors()<<"\n";

            battleNumber++;
        }
        catch (const std::exception& e) {
                std::cout<<"Battle skipped: "<<e.what()<<"\n";
        }
    }

}

int main() {
    battle();
}


