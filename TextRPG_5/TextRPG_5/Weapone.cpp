#include "stdafx.h"
#include "Weapone.h"


void CWeapone::RenderAbility() const
{
	cout << "�߰� ���ݷ� : " << m_iAttack;
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
