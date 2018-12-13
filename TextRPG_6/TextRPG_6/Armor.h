#pragma once
#include "Item.h"
class CArmor : public CItem
{
public:
	void RenderItem() const;

public:
	CArmor(const CItem& pC);
	CArmor(int _iType, string _strName, int _iPrice, int _iAbility);
	~CArmor();
};

