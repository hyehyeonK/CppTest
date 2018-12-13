#include "stdafx.h"
#include "Weapone.h"


void CWeapone::RenderAbility() const
{
	cout << "추가 공격력 : " << m_iAttack;
}

CWeapone::CWeapone()
{
}

CWeapone::CWeapone(char * szName, int iType, int iPrice, int iAttack)
	:CItem(szName, iType, iPrice), m_iAttack(iAttack)
{
}


CWeapone::~CWeapone()
{
}
