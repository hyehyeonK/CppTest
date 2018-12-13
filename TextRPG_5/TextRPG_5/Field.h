#pragma once
#include "Player.h"
#include "Monster.h"

class CField
{
private:
	CPlayer*	m_pPlayer;
	CMonster*	m_pMonster;

public:
	void Progress();
	void Fight();

public:
	void DrawMap() const;
	void CreateMonster(int iLevel);
public:
	CField(CPlayer* pPlayer);
	~CField();
};

