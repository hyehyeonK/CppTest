#include "stdafx.h"
#include "Field.h"

Field::Field(int iLevel)
{
	m_iLevel = iLevel;
}
void Field::CreateMonster()
{
	m_pMonster = nullptr;

	switch (m_iLevel)
	{ 
	case 1:
		m_pMonster = new Monster("ÃÊº¸¸÷", 30, 5);
		break;

	case 2:
		m_pMonster = new Monster("Áß¼ö¸÷", 50, 10);
		break;

	case 3:
		m_pMonster = new Monster("ÃÊº¸¸÷", 80, 15);
		break;
	}
}

void Field::Fight(Player* pPlayer)
{
	int iPlayerPower = pPlayer->GetPower();
	int iMonsterPower = m_pMonster->GetPower();

	while (true)
	{
		system("cls");
		pPlayer->PrintInfo();
		m_pMonster->PrintInfo();

		int iInput = 0;

		cout << "1. °ø°Ý\t2. µµ¸Á" << endl;
		cin >> iInput;

		if (2 == iInput)
		{
			break;
		}
		else if (1 == iInput)
		{
			
			pPlayer->ReduceHP(iMonsterPower);
			m_pMonster->ReduceHP(iPlayerPower);

			if (0 >= pPlayer->GetHp())
			{
				pPlayer->ResetHP();
				break;
			}
			if (0 >= m_pMonster->GetHp())
			{
				break;
			}
		}
		else
		{
			continue;
		}
	}

	delete(m_pMonster);
	m_pMonster = nullptr;
}