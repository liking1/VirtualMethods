#include "Unit.h"

Unit::Unit(const string& nameUnit, const size_t& health, const size_t& damage, const double& dodge) {
	setHealth(health);
	setDamege(damage);
	setDodge(dodge);
	setNameUnit(nameUnit);
	levelUnit = 1;
}
void Unit::setHealth(const size_t& health)
{

	if (health > 0)
		this->health = health;
}

void Unit::setDamege(const size_t& damage)
{
	if (damage > 0)
		this->damege = damage;
}

void Unit::setDodge(const double& dodge)
{
	if (dodge >= 0 && dodge <= 100)
		this->dodge = dodge;
}

void Unit::setNameUnit(const string& nameUnit)
{
	if (!nameUnit.empty())
		this->nameUnit = nameUnit;
}

size_t Unit::getHealth() const
{
	return health;
}

size_t Unit::getDamege() const
{
	return damege;
}

double Unit::getDodge() const
{
	return dodge;
}

string Unit::getNameUnit() const
{
	return nameUnit;
}

void Unit::levelUp()
{
	if (levelUnit < 6) {
		++levelUnit;
		setDamege(damege * levelUnit);
		setHealth(health * levelUnit);
	}
	else {
		cout << "Can't update max level" << endl;
	}
}

ostream& operator<<(ostream& ost, const Unit& unit)
{
	ost << "Name unit : " << unit.nameUnit << endl;
	ost << "Health : " << unit.health << endl;
	ost << "Damege : " << unit.damege << endl;
	ost << "Dodge : " << unit.dodge << "%" << endl;
	ost << "Level unit : " << unit.levelUnit << endl;
	return ost;
}