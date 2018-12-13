#include "stdafx.h"
#include "Field.h"

Field::Field(int iLevel, Player* pPlayer)
	:m_iLevel(iLevel), m_pPlayer(pPlayer)
{

}


Field::~Field()
{
}

void Field::createMonster()
{
	switch (m_iLevel)
	{
	case 1:
		m_pMonster = new Monster("�ʺ���", 50, 10);
		break;
	case 2:
		m_pMonster = new Monster("�߼���", 80, 20);
		break;
	case 3:
		m_pMonster = new Monster("�ʺ���", 110, 30);
		break;
	}
}

void Field::Fight()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pMonster->Render();
		cout << "1. ����\t2. ���� : ";
		cin >> iInput;

		if (2 == iInput)
		{
			break;
		}
		else if (1 == iInput)
		{
			m_pPlayer->Damage(m_pMonster->GetPower());
			m_pMonster->Damage(m_pPlayer->GetPower());
			
			if (0 >= m_pPlayer->GetHP())
			{
				m_pPlayer->ResetHP();
				break;
			}

			if (0 >= m_pMonster->GetHP())
			{
				break;
			}
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���." << endl;
			system("pause");
		}
	}
	SAFE_DELETE(m_pMonster);
}