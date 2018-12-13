#include "stdafx.h"
#include "Weapon.h"


void CWeapon::RenderInfo() const
{
	cout << "추가 공격력 : " << m_iAblity;
}

CWeapon::CWeapon()
{
}

CWeapon::CWeapon(const CItem & _rItem)
	:CItem(_rItem)
{
}

CWeapon::CWeapon(string _strName, int _iPrice, int _iAbility)
	:CItem(_strName, _iPrice, _iAbility)
{
}


CWeapon::~CWeapon()
{
}
