#include "stdafx.h"
#include "GameController.h"

void GameController::init()
{
	int iSelect = 0;
	while (iSelect == 0)
	{
		system("cls");
		iSelect = selectCharacter();
	}
	m_pPlayer = createPlayer(iSelect);

}
bool GameController::Play()
{
	while (true)
	{
		system("cls");
		int iSelect = 0;
		m_pPlayer->PrintInfo();
		cout << "1. �����\t2. ����" << endl;
		cin >> iSelect;

		if (iSelect == 2)
		{
			break;
		}
		else if (1 == iSelect)
		{
			while (true)
			{
				system("cls");
				m_pPlayer->PrintInfo();
				int iLevel = selectFieldLevel();
				if (0 == iLevel)
				{
					continue;
				}
				else if (4 == iLevel)
				{
					break;
				}
				else
				{
					m_pField = createField(iLevel);
					m_pField->Fight(m_pPlayer);
					delete(m_pField);
					m_pField = nullptr;
				}
			}
		}
		else
		{
			continue;
		}
	}
	
	delete(m_pPlayer);
	m_pPlayer = nullptr;
	
	return false;

}
int GameController::selectCharacter()
{
	int iSelect = 0;
	cout << "ĳ���͸� ������ �ּ���." << endl;
	cout << "1. ���� \t2. ������\t3. ����" << endl;
	cout << ">> ";
	cin >> iSelect;
	
	if (3 < iSelect || 1 > iSelect)
	{
		return 0;
	}

	return iSelect;
}

Player* GameController::createPlayer(int iSelect)
{
	Player* pPlayer = nullptr;

	switch (iSelect)
	{
	case 1:
		pPlayer = new Player("����", 100, 10);
		break;
	case 2:
		pPlayer = new Player("������", 80, 15);
		break;
	case 3:
		pPlayer = new Player("����", 90, 12);
		break;
	}

	return pPlayer;
}
int GameController::selectFieldLevel()
{
	int iLevel = 0;
	cout << "1. �ʱ� �����" << endl;
	cout << "2. �߱� �����" << endl;
	cout << "3. ��� �����" << endl;
	cout << "4. �ڷΰ���" << endl << endl;
	cout << "����͸� �����ϼ��� >> ";
	cin >> iLevel;

	if (4 < iLevel || 1 > iLevel)
	{
		return 0;
	}
	return iLevel;
}

Field* GameController::createField(int iLevel)
{
	m_pField = new Field(iLevel);
	m_pField->CreateMonster();
	return m_pField;
}