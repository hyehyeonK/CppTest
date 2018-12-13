#include "stdafx.h"
#include "Field.h"
#include "define.h"

CField::CField()
	:m_pPlayer(nullptr)
	,m_pMonster(nullptr)
{
}

CField::~CField()
{
}


void CField::Progress()
{
	int iLevel;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		DrawMap();
		cin >> iLevel;

		if (MENU_EXIT == iLevel)
			break;
		if (0 < iLevel && 4 > iLevel)
		{
			CreateMonster(iLevel);
			Fight();
			SAFE_DELETE(m_pMonster);
		}
		else
		{
			REJECT_INPUT;
		}

	}
}

void CField::DrawMap() const
{
	cout << "\n================< MAP >================" << endl;
	cout << "1. ÃÊº¸¸Ê" << endl;
	cout << "2. Áß¼ö¸Ê" << endl;
	cout << "3. °í¼ö¸Ê" << endl;
	cout << "4. µÚ·Î°¡±â" << endl;
}

void CField::CreateMonster(int _iLevel)
{
	switch (_iLevel)
	{
	case LEV_EASY:
		m_pMonster = new CMonster("ÃÊº¸¸÷", 10, 30, 100);
		break;

	case LEV_MID:
		m_pMonster = new CMonster("Áß¼ö¸÷", 30, 60, 500);
		break;

	case LEV_HARD:
		m_pMonster = new CMonster("ÃÊº¸¸÷", 50, 90, 1000);
		break;
	}
}

void CField::Fight()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		m_pMonster->RenderInfo();

		cout << "\n1. °ø°Ý\t2. µµ¸Á" << endl;
		cin >> iInput;

		if (RUNAWAY == iInput) break;

		if (ATTACK == iInput)
		{
			m_pPlayer->SetDamage(m_pMonster->GetPower());
			m_pMonster->SetDamage(m_pPlayer->GetPower());

			if (0 >= m_pPlayer->GetHP())
			{
				dynamic_cast<CPlayer*>(m_pPlayer)->ResetHP();
				break;
			}

			if (0 >= m_pMonster->GetHP())
			{
				dynamic_cast<CPlayer*>(m_pPlayer)->EarnMoney(m_pMonster->GetMoney());
				break;
			}
		}
		else
		{
			REJECT_INPUT;
		}


	}
}