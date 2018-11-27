#pragma once

class Monster
{
private:

	char	m_szName[128];
	int		m_iHP;
	int		m_iPower;

public:
	Monster(char* szName, int iHP, int iPower);
	void PrintInfo();
	int GetHp();
	void ReduceHP(int iPower);
	int GetPower();
};