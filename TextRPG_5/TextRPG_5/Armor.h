#pragma once
#include "Item.h"

class CArmor : public CItem
{
private:
	int m_iDefense;
public:
	void RenderAbility() const;
public:
	inline int GetAbility() const { return m_iDefense; };

public:
	CArmor();
	CArmor(char* szName, int iType, int iPrice, int iDefense);
	~CArmor();
};

