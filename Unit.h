#pragma once
#include <iostream>
#include <vector>

using namespace std;
class  Unit
{
public:
	Unit(const string& nameUnit = "Unit", const size_t& health = 1, const size_t& damage = 1, const double& dodge = 0);
	void setHealth(const size_t& health);
	void setDamege(const size_t& damage);
	void setDodge(const double& dodge);
	void setNameUnit(const string& nameUnit);
	size_t getHealth() const;
	size_t getDamege() const;
	double getDodge() const;
	string getNameUnit() const;

	void upLevel();
	friend ostream& operator<<(ostream& os, const Unit& obj);

protected:
	string nameUnit;
	size_t health;
	size_t damege;
	double dodge;
	size_t levelUnit;
};