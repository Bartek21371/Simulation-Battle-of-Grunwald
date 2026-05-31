#include <iostream>
#include <string>
#include <fstream>
#include <config/ConfigLoader.hpp>
#include <core/Battle.hpp>
#include <reports/BattleReport.hpp>

//Gui
#include <QApplication>
#include <gui/MainWindow.hpp>

// Battle loop with load config and save result


void battle() {
    std::vector<FractionConfig> config = ConfigLoader::LoadFromFile("../assets/configs/testfile_someinfected.csv",false);

    int battleNumber{1};

    std::string filename = "../assets/reports/battleReport1.csv";

    std::ofstream file(filename);
    file<<"Battle,Winner,Rounds,Hussars Alive,Teutonic Alive,Hussars Total Damage,Teutonic Total Damage,Hussars Kills,Teutonic Kills,Weather,Status,Date\n";
    file.close();


    for (size_t i = 0; i < config.size()-1; i+=2) {
        try {
            std::cout<<"========================"<<"\n";
            std::cout<<"Battle "<<battleNumber<<"\n";
            std::cout<<config[i].fraction<<" vs "<<config[i+1].fraction<<"\n";
            std::cout<<"========================"<<"\n";

            Army Hussars(config[i]);
            Army Teutonic(config[i + 1]);

            Battle battle(Hussars, Teutonic);

            battle.start_Battle();
            std::cout<<"Weather: "<<battle.get_Weather()<<"\n";

            std::cout<<"Winner: "<<battle.get_Winner()<<"\n";

            std::cout<<"Rounds: "<<battle.get_Rounds()<<"\n";

            std::cout<<"Alive "<<config[i].fraction<<":"<<battle.get_HussarsArmy().count_AliveWarriors()<<"\n";
            std::cout<<"Alive "<<config[i+1].fraction<<":"<<battle.get_TeutonicArmy().count_AliveWarriors()<<"\n";

            std::cout<<"Hussars Total Damage: "<<battle.get_Stats().get_HussarsDamage_Dealt()<<"\n";
            std::cout<<"Teutonic Total Damage: "<<battle.get_Stats().get_TeutonicDamage_Dealt()<<"\n";

            std::cout<<"Hussars kills: "<<battle.get_Stats().get_HussarsKills()<<"\n";
            std::cout<<"Teutonic kills: "<<battle.get_Stats().get_TeutonicKills()<<"\n";

            BattleReport::save(battle, filename, battleNumber);

        }
        catch (const std::exception& e) {
            std::cout<<"Battle skipped: "<<e.what()<<"\n";

            BattleReport::save_skipped(filename, battleNumber, e.what());
        }

        battleNumber++;
    }
}

int main(int argc, char *argv[]) {
    //battle();
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();

}


