#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
	:m_pArmor(nullptr), m_pWeapon(nullptr)
{
}

CPlayer::CPlayer(string strName, int iHP, int iPower)
	:CObj(strName, iHP, iPower, 1000)
	, m_iOriginHP(iHP)
	, m_pArmor(nullptr), m_pWeapon(nullptr)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::ResetHP()
{
	m_iHP = m_iOriginHP;
}

bool CPlayer::SpendMoney(int iPrice)
{
	if (0 > (m_iMoney - iPrice)) 
		return false;
	else 
	{
		m_iMoney -= iPrice;
		return true;
	}
}

void CPlayer::SetDamage(const int iPower)
{
	if (nullptr != m_pArmor)
	{
		float iDefense = 100.0f - m_pArmor->GetAblity();
		iDefense *= 0.01f;
		m_iHP -= iPower * iDefense;
	}
	else
	{
		m_iHP -= iPower;
	}
}

const int CPlayer::GetPower() const
{
	if (nullptr != m_pWeapon)
	{
		return m_iPower + m_pWeapon->GetAblity();
	}
	else return m_iPower;
}

void CPlayer::RenderInfo() const
{
	CObj::RenderInfo();

	if (nullptr != m_pWeapon)
	{
		cout << "公扁 : " << m_pWeapon->GetName() << "( ";
		m_pWeapon->RenderItem();
		cout << " )" << endl;
	}

	if (nullptr != m_pArmor)
	{
		cout << "规绢备 : " << m_pArmor->GetName() << "( ";
		m_pArmor->RenderItem();
		cout << " )" << endl;
	}
	
	cout << "家瘤陛 : " << m_iMoney << endl;
}
