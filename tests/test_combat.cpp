//
// Created by bart on 14.05.2026.
//

#include <warriors/Warrior.hpp>
#include <config/ConfigLoader.hpp>


// Test combat of warrior1 on warrior 2

void test_combat() {
    std::vector<FractionConfig> config1 = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv");

    Warrior warrior1 = Warrior(config1[0].knight_stats);
    Warrior warrior2 = Warrior(config1[1].knight_stats);

    std::cout<<"Warrior1 health: "<<warrior1.get_Health()<<"\n";
    std::cout<<"Warrior1 attack: "<<warrior1.get_Attack()<<"\n";
    std::cout<<"Warrior2 health: "<<warrior2.get_Health()<<"\n";
    std::cout<<"Warrior2 attack: "<<warrior2.get_Attack()<<"\n";

    while (warrior2.get_Health() > 0) {
        warrior1.attack_Enemy(warrior2);
        std::cout<<"After attack:"<<"\n";
        std::cout<<"Warrior1 health: "<<warrior1.get_Health()<<"\n";
        std::cout<<"Warrior1 attack: "<<warrior1.get_Attack()<<"\n";
        std::cout<<"Warrior2 health: "<<warrior2.get_Health()<<"\n";
        std::cout<<"Warrior2 attack: "<<warrior2.get_Attack()<<"\n";
    }
    std::cout<<"Warrior2 is alive: "<<warrior2.is_Alive()<<"\n";
}

int main() {
    test_combat();
}