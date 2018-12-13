#include "stdafx.h"
#include "Armor.h"

void CArmor::RenderItem() const
{
	cout << "¹æ¾î·Â : " << m_iAbility << "%";
}

CArmor::CArmor(const CItem & pC)
	:CItem(pC)
{
}

CArmor::CArmor(int _iType, string _strName, int _iPrice, int _iAbility)
	:CItem(_iType, _strName, _iPrice, _iAbility)
{
}


CArmor::~CArmor()
{
}
