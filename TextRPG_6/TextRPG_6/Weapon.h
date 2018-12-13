#pragma once
#include "Item.h"

class CWeapon : public CItem
{

public:
	void RenderItem() const;

public:
	CWeapon(const CItem& pC);
	CWeapon(int _iType, string _strName, int _iPrice, int _iAbility);
	~CWeapon();
};

