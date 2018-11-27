#pragma once
#include "Monster.h"
#include "Player.h"

class Field
{
public:

	int m_iLevel;
	Monster* m_pMonster;

public:
	Field(int iLevel);
	void CreateMonster();
	void Fight(Player* pPlayer);
	
};