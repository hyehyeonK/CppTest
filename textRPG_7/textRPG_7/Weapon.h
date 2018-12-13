#pragma once
#include "Item.h"

class CWeapon : public CItem
{
public:
	virtual void RenderInfo() const override;

public:
	CWeapon();
	CWeapon(const CItem& _rItem);
	CWeapon(string _strName, int _iPrice, int _iAbility);
	~CWeapon();
};

