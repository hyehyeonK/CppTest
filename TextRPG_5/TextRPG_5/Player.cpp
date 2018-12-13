#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
	:m_iOriginHP(0), m_pArmor(nullptr), m_pWeapone(nullptr)
{
}

CPlayer::CPlayer(char * szName, int iHP, int iPower, int iMoney)
	:CObj(szName, iHP, iPower), m_iOriginHP(iHP), m_iMoney(iMoney), m_pArmor(nullptr), m_pWeapone(nullptr)
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
	int temp = m_iMoney - iPrice;
	if (temp >= 0)
	{
		m_iMoney = temp;
		return true;
	}
	else return false;
}

void CPlayer::RenderInfo() const
{
	CObj::RenderInfo();

	if (m_pArmor != nullptr) 
	{
		m_pArmor->RenderAbility();
		cout << endl;
	}
	if (m_pWeapone != nullptr) 
	{
		m_pWeapone->RenderAbility();
		cout << endl;
	}

	cout << "¼ÒÁö±Ý : " << m_iMoney << endl;
	cout << endl;
}

void CPlayer::SetArmor(CItem* pItem)
{
	m_pArmor = pItem;
}

void CPlayer::SetWeapone(CItem * pItem)
{
	m_pWeapone = pItem;
}

int CPlayer::GetPower() const
{
	if (m_pWeapone != nullptr)
	{
		return m_iPower + m_pWeapone->GetAbility();
	}
	else return m_iPower;
	
}

void CPlayer::Damaged(int iPower)
{
	cout << "Player Damage" << endl;
	double iArmor = 1.0;
	if (nullptr != m_pArmor)
	{
		iArmor = (100 - m_pArmor->GetAbility()) / 100.0;
	}
	m_iHP -= iPower * iArmor;
	
}
