#include "stdafx.h"
#include "Monster.h"

Monster::Monster(char* szName, int iHP, int iPower)
	:m_tInfo(szName, iHP, iPower)
{

}

Monster::~Monster()
{
}

void Monster::Render() const
{
	cout << "< " << m_tInfo.szName << " >" << endl;
	cout << "Power : " << m_tInfo.iPower << "\tHP : " << m_tInfo.iHP << endl;
	cout << "=============================" << endl;
}

void Monster::Damage(int iPower)
{
	m_tInfo.iHP -= iPower;
}

int Monster::GetHP()
{
	return m_tInfo.iHP;
}
int Monster::GetPower()
{
	return m_tInfo.iPower;
}