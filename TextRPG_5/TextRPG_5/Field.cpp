#include "stdafx.h"
#include "Field.h"


CField::CField(CPlayer* pPlayer)
	:m_pPlayer(pPlayer)
{
}


CField::~CField()
{
}


void CField::Progress()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		DrawMap();
		cin >> iInput;

		if (4 == iInput) { break; }

		if (4 > iInput && 0 < iInput)
		{
			CreateMonster(iInput);
			Fight();
		}
		else
		{
			cout << "잘못된 선택입니다." << endl;
			system("pause");
		}
	}
}


void CField::DrawMap() const
{
	cout << "1. 초보맵" << endl;
	cout << "2. 중수맵" << endl;
	cout << "3. 고수맵" << endl;
	cout << "4. 뒤로가기" << endl;
}

void CField::CreateMonster(int iLevel)
{
	switch (iLevel)
	{
	case 1:
		m_pMonster = new CMonster("초보몹", 50, 30, 10);
		break;
	case 2:
		m_pMonster = new CMonster("중수몹", 70, 40, 50);
		break;
	case 3:
		m_pMonster = new CMonster("고수몹", 90, 50, 100);
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
		cout << "\n1. 공격\t2. 도망 : ";
		cin >> iInput;

		if (2 == iInput) { break; }

		if (1 == iInput)
		{
			m_pMonster->Damaged(m_pPlayer->GetPower());
			m_pPlayer->Damaged(m_pMonster->GetPower());

			if (0 >= m_pPlayer->GetHP())
			{
				m_pPlayer->ResetHP();
				break;
			}
			if (0 >= m_pMonster->GetHP())
			{
				m_pPlayer->EarnMoney(m_pMonster->GetCoin());
				break;
			}
		}
		else
		{
			cout << "잘못된 선택입니다." << endl;
			system("pause");
		}
	}

	SAFE_DELETE(m_pMonster);
}