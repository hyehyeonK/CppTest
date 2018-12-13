#include "stdafx.h"
#include "Player.h"


Player::Player()
 :m_iOriginHP(0)
{
}
Player::Player(char* szName, int iHP, int iPower)
	:m_iOriginHP(iHP), m_tInfo(szName, iHP, iPower)
{
}

void Player::Render() const
{
	cout << "< " << m_tInfo.szName << " >" << endl;
	cout << "Power : " << m_tInfo.iPower << "\tHP : " << m_tInfo.iHP << endl;
	cout << "=============================" << endl;
}

void Player::Damage(int iPower)
{
	m_tInfo.iHP -= iPower;
}
void Player::ResetHP()
{
	m_tInfo.iHP = m_iOriginHP;
}
int Player::GetHP()
{
	return m_tInfo.iHP;
}
int Player::GetPower()
{
	return m_tInfo.iPower;
}