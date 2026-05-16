//
// Created by bart on 15.05.2026.
//


#include <core/Army.hpp>
#include <config/ConfigLoader.hpp>

// Test creating army

void test_army() {

    std::vector<FractionConfig> config1 = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv");

    Army Hussars = Army(config1[0]);
    Army Teutonic = Army(config1[1]);

    // Check armies size
    std::cout<<"Army size: "<<Hussars.get_ArmySize()<<"\n";
    std::cout<<"Army size: "<<Teutonic.get_ArmySize()<<"\n";

    std::cout<<"---------------------------------------------------------------"<<"\n";

    // Check health of each warrior in army
    std::cout<<"Health of hussars warriors:"<<"\n";
    for (Warrior& w : Hussars.get_Warriors()) {
        std::cout << w.get_Health() << "\n";
    }

    std::cout<<"Health of teutonic warriors:"<<"\n";
    for (Warrior& w : Teutonic.get_Warriors()) {
        std::cout << w.get_Health() << "\n";
    }
    std::cout<<"---------------------------------------------------------------"<<"\n";

    // Count alive warriors in armies after combat
    std::cout<<"Before combat: "<<"\n";

    std::cout<<"Alive hussars: "<<Hussars.count_AliveWarriors()<<"\n";
    std::cout<<"Alive teutonic: "<<Teutonic.count_AliveWarriors()<<"\n";

    std::cout<<"After combat: "<<"\n";

    while (Teutonic.get_Warriors()[0].is_Alive()) {
        Hussars.get_Warriors()[0].attack_Enemy(Teutonic.get_Warriors()[0]);
        std::cout<<"Enemy health: "<<Teutonic.get_Warriors()[0].get_Health()<<"\n";
    }
    std::cout<<"Alive hussars: "<<Hussars.count_AliveWarriors()<<"\n";
    std::cout<<"Alive teutonic: "<<Teutonic.count_AliveWarriors()<<"\n";

}

int main() {
    test_army();
}