#include "stdafx.h"
#include "creature.h"

Creature::Creature(char* pName, int _iHP, int _iPower)
{
	strcpy_s(szName, pName);
	iHP = _iHP;
	iDefaultHP = iHP;
	iPower = _iPower;
	
}

void Creature::printCreatureInfo()
{
	cout << "================" << szName << "================" << endl;
	cout << "HP : " << iHP << "\tPower : " << iPower << endl;
	cout << "=====================================" << endl;
}
void Creature::attacked(int _iPower)
{
	iHP -= _iPower;
}
int Creature::getPower()
{
	return iPower;
}
int Creature::getHP()
{
	return iHP;
}
void Creature::resurrectionCharacter()
{
	iHP = iDefaultHP;
}
