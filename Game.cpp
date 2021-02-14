#include <iostream>
#include "Team.h"
#include "Game.h"

int main()
{
    Team team("First");
    Team team2("Second");
    GAME game;

    game.Battle(team, team2);
    game.Battle(team, team2);
}
