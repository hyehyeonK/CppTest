#pragma once
#include "Obj.h"

class CMonster : public CObj
{
private:
	const int	m_iCoin;

public:
	inline const int GetCoin() const { return m_iCoin; }
public:
	CMonster(char* szName, int iHP, int iPower, int iCoin);
	CMonster();
	~CMonster();
};

