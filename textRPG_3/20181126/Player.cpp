#include "stdafx.h"
#include "Player.h"

Player::Player(char* szName, int iHP, int iPower)
{
	strcpy_s(m_szName, szName);
	m_iHP = iHP;
	m_iOriginHP = iHP;
	m_iPower = iPower;
}
void Player::PrintInfo()
{
	cout << "===================" << m_szName << "===================" << endl;
	cout << "Power : " << m_iPower << "\tHP : " << m_iHP << endl;
	cout << "=========================================" << endl;
}
int Player::GetHp()
{
	return m_iHP;
}
void Player::ResetHP()
{
	m_iHP = m_iOriginHP;
}

void Player::ReduceHP(int iPower)
{
	m_iHP -= iPower;
}

int Player::GetPower()
{
	return m_iPower;
}