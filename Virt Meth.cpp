#include <iostream>
#include "Team.h"
#include "Game.h"

using namespace std;
void GAME::Battle(Team& firstTeam, Team& secondTeam)
{
    if (firstTeam.isNoKillUnit() && secondTeam.isNoKillUnit()) {
        searchForAnOpponent(firstTeam, secondTeam);
    }
    else {
        if (!firstTeam.isNoKillUnit() && secondTeam.isNoKillUnit()) {
            cout << "WIN team " << secondTeam.getName() << "because " << firstTeam.getName() << "didn't hame lives units" << endl;
        }
        else if (firstTeam.isNoKillUnit() && !secondTeam.isNoKillUnit()) {
            cout << "WIN team " << firstTeam.getName() << "because " << secondTeam.getName() << "didn't hame lives units" << endl;
        }
        else {
            cout << "Draw because both didn't have lives units" << endl;
        }
    }

}

void GAME::searchForAnOpponent(Team& firstTeam, Team& secondTeam)
{
    bool win = false;
    bool winFirst = false;
    bool winSecond = false;
    bool winThird = false;
    bool first = false;
    bool second = false;
    bool third = false;
    vector<int> unitFirstTeam;
    vector<int> unitSecondTeam;



    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (firstTeam.team[i].getNameUnit() == secondTeam.team[j].getNameUnit()) {
                if (j == 0) {
                    winFirst = batleTwo(firstTeam.team[i], secondTeam.team[j]);
                    first = true;
                    break;
                }
                else if (j == 1) {
                    winSecond = batleTwo(firstTeam.team[i], secondTeam.team[j]);
                    second = true;
                    break;
                }
                else if (j == 2) {
                    winThird = batleTwo(firstTeam.team[i], secondTeam.team[j]);
                    third = true;
                    break;
                }
            }
        }
    }
    if ((winFirst == true && winSecond == true) || (winThird == true && winSecond == true) || (winFirst == true && winThird == true) || (winFirst == true && winSecond == true && winThird == true)) {
        cout << "Winner team " << firstTeam.getName() << endl;
    }
    else {
        cout << "Winner team " << secondTeam.getName() << endl;
    }
}

bool GAME::batleTwo(Unit& firstUnit, Unit& secondUnit)
{
    srand(time(NULL));
    bool isKill = false;
    while (isKill != true) {
        size_t tryFisrt = rand() % 100;

        isKill = shot(firstUnit, secondUnit, tryFisrt);
        if (isKill == true) {
            return true;
        }
        isKill = false;
        size_t tryF = rand() % 100;
        isKill = shot(secondUnit, firstUnit, tryF);
        if (isKill == true) {
            return false;
        }
    }

    return firstUnit.getHealth() == 0;
}

bool GAME::shot(Unit& unitFirst, Unit& unitSecond, const size_t& tr)
{
    if (tr > (size_t)unitFirst.getDodge()) {
        int temp = (unitFirst.getHealth() - unitSecond.getDamege());
        cout << "Unit " << unitFirst.getNameUnit() << " is shot and hit" << endl;
        if (temp <= 0) {
            unitFirst.setHealth(0);
            return true;
        }
        else {
            unitFirst.setHealth(unitFirst.getHealth() - unitSecond.getDamege());
        }
    }
    else {
        cout << "Unit " << unitFirst.getNameUnit() << " is shot and missed" << endl;
    }
    return false;
}