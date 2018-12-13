#pragma once
#include "Player.h"
#include "Monster.h"

class CField
{
private:
	CObj* m_pPlayer;
	CObj* m_pMonster;

public:
	inline void SetPlayer(CObj* _pPlayer) { m_pPlayer = _pPlayer; }
	void Progress();

private:
	void DrawMap() const;
	void CreateMonster(int _iLevel);
	void Fight();
public:
	CField();
	~CField();
};

