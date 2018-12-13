#pragma once
#include "define.h"

class Monster
{
public:
	int GetHP();
	int GetPower();

public :
	void Render() const;
	void Damage(int iPower);

public:
	Monster(char* szName, int iHP, int iPower);
	~Monster();

private:
	INFO	m_tInfo;
};