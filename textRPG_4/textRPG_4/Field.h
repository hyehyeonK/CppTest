#pragma once
#include "Player.h"
#include "Monster.h"
class Field
{
public:
	void createMonster();
	void Fight();
public:
	Field(int iLevel, Player* pPlayer);
	~Field();

private:
	const int	 m_iLevel;
	Player*		 m_pPlayer;
	Monster*	 m_pMonster;
};