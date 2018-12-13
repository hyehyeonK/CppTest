#include "stdafx.h"
#include "Field.h"
#include "define.h"

CField::CField(CObj* _pPlayer)
	:m_pPlayer(_pPlayer), m_pMonster(nullptr)
{
}

CField::~CField()
{
}

void CField::Progress()
{
	int iLevel = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		DrawMap();
		cin >> iLevel;
		
		if (MENU_EXIT == iLevel)
			break;
		else if (0 < iLevel && 4 > iLevel)
		{
			CreateMonster(iLevel);
			Fight();
			SAFE_DELETE(m_pMonster);
		}
		else
		{
			cout << "\n****잘못 된 입력 입니다.****\n" << endl;
			system("pause");
		}
	}
}

void CField::CreateMonster(int iLevel)
{
	switch (iLevel)
	{
	case LEV_EASY:
		m_pMonster = new CMonster("초보몹", 20, 10, 100);
		break;

	case LEV_MID:
		m_pMonster = new CMonster("중수몹", 50, 20, 300);
		break;

	case LEV_HARD:
		m_pMonster = new CMonster("중수몹", 80, 30, 500);
		break;
	}
}

void CField::Fight()
{
	int iInput;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		m_pMonster->RenderInfo();
		cout << "\n1.공격\t2.도망 : " << endl;
		cin >> iInput;

		if (2 == iInput)
			break;

		if (1 == iInput)
		{
			m_pMonster->SetDamage(m_pPlayer->GetPower());
			m_pPlayer->SetDamage(m_pMonster->GetPower());

			if (0 >= m_pPlayer->GetHP())
			{
				m_pPlayer->ResetHP();
				break;
			}

			if (0 >= m_pMonster->GetHP())
			{
				m_pPlayer->EarnMoney(m_pMonster->GetMoney());
				break;
			}
		}
		else
		{
			cout << "\n****잘못 된 입력 입니다.****\n" << endl;
			system("pause");
		}
	}
	
}

void CField::DrawMap()
{
	cout << "\n=============< 사냥터 >============" << endl;
	cout << "1. 초보맵" << endl;
	cout << "2. 중수맵" << endl;
	cout << "3. 고수맵" << endl;
	cout << "4. 뒤로가기" << endl;
}
