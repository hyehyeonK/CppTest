#pragma once

class Creature
{
private:
	char szName[128];
	int iHP;
	int iPower;
	int iDefaultHP;

public:
	
	Creature(char* pName, int _iHP, int _iPower);
	void printCreatureInfo();
	void attacked(int _iPower);
	int getPower();
	int getHP();
	void resurrectionCharacter();
};
