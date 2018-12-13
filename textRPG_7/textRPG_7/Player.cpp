#include "stdafx.h"
#include "Player.h"
#include "define.h"

CPlayer::CPlayer()
	:m_pArmor(nullptr), m_pWeapon(nullptr)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::RenderInfo() const
{
	CObj::RenderInfo();
	if (nullptr != m_pWeapon)
	{
		cout << "\t\t\t*";
		m_pWeapon->RenderInfo();
		cout << endl;
	}

	if (nullptr != m_pArmor)
	{
		cout << "\t\t\t*";
		m_pArmor->RenderInfo();
		cout << endl;
	}
		
	cout << "������ : " << m_iMoney << endl;
}

void CPlayer::SetDamage(int _iPower)
{
	if (nullptr != m_pArmor)
	{
		float iDefense = m_pArmor->GetAbility() * 0.01;
		_iPower -= _iPower * iDefense;
	}
	m_iHp -= _iPower;
}

int CPlayer::GetPower() const
{
	if (nullptr != m_pWeapon)
	{
		return m_iPower + m_pWeapon->GetAbility();
	}
	else
	{
		return m_iPower;
	}
}

void CPlayer::SelectJob()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		cout << "================< ���� >================" << endl;
		cout << "\n1. ���� \t2. ������\t3. ����" << endl;
		cout << "\n� ������ �����Ͻðڽ��ϱ�? : ";
		cin >> iInput;

		switch (iInput)
		{
		case JOB_WARRIOR:
			m_strName = "����";
			m_iPower = 20;
			m_iOriginHP = 100;
			m_iHp = m_iOriginHP;
			m_iMoney = 1000;
			return;

		case JOB_WIZARD:
			m_strName = "������";
			m_iPower = 30;
			m_iOriginHP = 80;
			m_iHp = m_iOriginHP;
			m_iMoney = 1000;
			return;

		case JOB_THIEF:
			m_strName = "����";
			m_iPower = 25;
			m_iOriginHP = 90;
			m_iHp = m_iOriginHP;
			m_iMoney = 1000;
			return;

		default:
			REJECT_INPUT
			break;
		}
	}
}

bool CPlayer::SpendMoney(int _iPrice)
{
	if (0 > m_iMoney - _iPrice) return false;
	else
	{
		m_iMoney -= _iPrice;
		return true;
	}
}
