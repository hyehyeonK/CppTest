#pragma once
#include "Item.h"
class CArmor : public CItem
{
public:
	virtual void RenderInfo() const override;
public:
	CArmor();
	CArmor(const CItem& _rItem);
	CArmor(string _strName, int _iPrice, int _iAbility);
	~CArmor();
};

