#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}

CMonster::CMonster(string strName, int iHP, int iPower, int iMoney)
	:CObj(strName, iHP, iPower, iMoney)
{
}


CMonster::~CMonster()
{
}

void CMonster::RenderInfo() const
{
	CObj::RenderInfo();
	cout << "Çö»ó±Ý : " << m_iMoney << endl;
}

void CMonster::ResetHP()
{
}

bool CMonster::SpendMoney(int iPrice)
{
	return false;
}

void CMonster::EarnMoney(int iCoin)
{
}

void CMonster::SetArmor(CItem * pArmor)
{
}

CItem * CMonster::GetArmor()
{
	return nullptr;
}

void CMonster::SetWeapon(CItem * pWeapon)
{
}

CItem * CMonster::GetWeapon()
{
	return nullptr;
}
