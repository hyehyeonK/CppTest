#include "stdafx.h"
#include "Weapon.h"

void CWeapon::RenderItem() const
{
	cout << "�߰� ���ݷ� : " << m_iAbility;
}

CWeapon::CWeapon(const CItem & pC)
	:CItem(pC)
{
}

CWeapon::CWeapon(int _iType, string _strName, int _iPrice, int _iAbility)
	:CItem(_iType, _strName, _iPrice, _iAbility)
{
}

CWeapon::~CWeapon()
{
}
