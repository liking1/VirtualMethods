#include <iostream>
#include"Team.h"
#include "Game.h"

int main()
{
    Team TEAM2("First");
    Team TEAM("Second");
    GAME game;

    game.Battle(TEAM, TEAM2);
    game.Battle(TEAM, TEAM2);

}
