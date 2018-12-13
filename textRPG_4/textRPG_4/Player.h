#pragma once
#include "define.h"

class Player
{

public:
	void ResetHP();
	int GetHP();
	int GetPower();

public:
	void Render() const;
	void Damage(int iPower);

public:
	Player();
	explicit Player(char* szName, int iHP, int iPower);
	~Player() {}

private:
	INFO			m_tInfo;
	const int		m_iOriginHP;
};
