#include "stdafx.h"
#include "Armor.h"


void CArmor::RenderAbility() const
{
	cout << "���� : " << m_iDefense << '%';
}

CArmor::CArmor()
{

}

CArmor::CArmor(char * szName, int iType, int iPrice, int iDefense)
	:CItem(szName, iType, iPrice), m_iDefense(iDefense)
{
}


CArmor::~CArmor()
{
}
