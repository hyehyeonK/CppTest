#pragma once
#include "Item.h"
class CWeapone : public CItem
{
private:
	int m_iAttack;
public:
	void RenderAbility() const;
public:
	inline int GetAbility() const { return m_iAttack; };

public:
	CWeapone();
	CWeapone(char* szName, int iType, int iPrice, int iAttack);
	~CWeapone();
};

