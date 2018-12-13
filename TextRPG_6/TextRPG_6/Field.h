#pragma once
#include "Player.h"
#include "Monster.h"
class CField
{
private:
	CObj* m_pPlayer;
	CObj* m_pMonster;

public:
	void Progress();

private:
	void CreateMonster(int iLevel);
	void Fight();
	void DrawMap();

public:
	CField(CObj* _pPlayer);
	~CField();
};

