#include "Archer.h"

Archer::Archer() : Unit("Archer", 12, 4, 40)
{
}

void Archer::levelUp()
{
	Unit::levelUp();
}