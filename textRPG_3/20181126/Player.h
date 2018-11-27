#pragma once

class Player
{
private:

	char	m_szName[128];
	int		m_iHP;
	int		m_iOriginHP;
	int		m_iPower;

public:
	Player (char* szName, int iHP, int iPower);
	void PrintInfo();
	int GetHp();
	void ResetHP();
	void ReduceHP(int iPower);
	int GetPower();
};