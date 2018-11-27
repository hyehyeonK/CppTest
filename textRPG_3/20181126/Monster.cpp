#include "stdafx.h"
#include "Monster.h"

Monster::Monster(char* szName, int iHP, int iPower)
{
	strcpy_s(m_szName, szName);
	m_iHP = iHP;
	m_iPower = iPower;
}
void Monster::PrintInfo()
{
	cout << "===================" << m_szName << "===================" << endl;
	cout << "Power : " << m_iPower << "\tHP : " << m_iHP << endl;
	cout << "=========================================" << endl;
}
int Monster::GetHp()
{
	return m_iHP;
}

void Monster::ReduceHP(int iPower)
{
	m_iHP -= iPower;
}
int Monster::GetPower()
{
	return m_iPower;
}