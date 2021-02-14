#include "Team.h"

void Team::levelUp()
{
	for (auto& v : team) {
		v.levelUp();
	}
}
Team::Team(const string& nameTeam)
{
	setNameTeam(nameTeam);

	randomUnit();
}

vector<string> Team::nameTeams;

void Team::setNameTeam(const string nameTeam)
{
	bool isFound = false;
	for (auto& v : nameTeams) {
		if (v == nameTeam) {
			isFound = true;
		}
	}
	if (!isFound) {
		this->nameTeam = nameTeam;
		nameTeams.push_back(nameTeam);
	}
	else {
		cout << "Name is busy . Enter new name" << endl;
		string temp;
		getline(cin, temp);
		setNameTeam(temp);
	}
}

void Team::randomUnit()
{
	srand(time(NULL));
	for (size_t i = 0; i < countUnit; i++)
	{
		size_t a = rand() % 3;
		if (a == 0) {
			team.push_back(Swordsman());
		}
		else if (a == 1) {
			team.push_back(Archer());
		}
		else {
			team.push_back(Mage());
		}
	}

}

bool Team::isNoKillUnit() const
{
	for (auto& v : this->team) {
		if (v.getHealth() != 0) {
			return true;
		}
	}
	return false;
}

string Team::getName() const
{
	return nameTeam;
}

size_t Team::getCountTeam() const
{
	return countUnit;
}

ostream& operator<<(ostream& ost, const Team& t)
{
	ost << "Team's name : " << t.nameTeam << endl;
	ost << endl;
	for (auto& v : t.team) {
		ost << v << endl;
	}
	return ost;
}