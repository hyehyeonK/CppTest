#include "stdafx.h"
#include "Armor.h"


void CArmor::RenderInfo() const
{
	cout << "���� : " << m_iAblity << "%";
}

CArmor::CArmor()
{
}

CArmor::CArmor(const CItem & _rItem)
	:CItem(_rItem)
{
}

CArmor::CArmor(string _strName, int _iPrice, int _iAbility)
	:CItem(_strName, _iPrice, _iAbility)
{
}


CArmor::~CArmor()
{
}
