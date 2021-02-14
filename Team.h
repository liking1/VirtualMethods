#pragma once
#include<iostream>	
#include<vector>
#include<string>
#include <ctime>
#include "Unit.h"
#include "Mage.h"
#include "Archer.h"
#include "Swordsman.h"

using namespace std;
class Team
{
public:
	friend class GAME;
	Team(const string& nameTeam = "NoName");
	bool isNoKillUnit() const;
	friend ostream& operator<<(ostream& os, const Team& obj);
	string getName() const;
	size_t getCountTeam() const;
	void Uplevel();
private:
	void randomUnit();
	vector<Unit> team;
	void setNameTeam(const string nameTeam);
	static const size_t countUnit = 3;
	string nameTeam;
	static vector<string> nameTeams;

};