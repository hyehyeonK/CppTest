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
			cout << "�߸��� �����Դϴ�." << endl;
			system("pause");
		}
	}
}


void CField::DrawMap() const
{
	cout << "1. �ʺ���" << endl;
	cout << "2. �߼���" << endl;
	cout << "3. �����" << endl;
	cout << "4. �ڷΰ���" << endl;
}

void CField::CreateMonster(int iLevel)
{
	switch (iLevel)
	{
	case 1:
		m_pMonster = new CMonster("�ʺ���", 50, 30, 10);
		break;
	case 2:
		m_pMonster = new CMonster("�߼���", 70, 40, 50);
		break;
	case 3:
		m_pMonster = new CMonster("�����", 90, 50, 100);
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
		cout << "\n1. ����\t2. ���� : ";
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
			cout << "�߸��� �����Դϴ�." << endl;
			system("pause");
		}
	}

	SAFE_DELETE(m_pMonster);
}