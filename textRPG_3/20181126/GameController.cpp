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
		cout << "1. 사냥터\t2. 종료" << endl;
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
	cout << "캐릭터를 선택해 주세요." << endl;
	cout << "1. 전사 \t2. 마법사\t3. 도적" << endl;
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
		pPlayer = new Player("전사", 100, 10);
		break;
	case 2:
		pPlayer = new Player("마법사", 80, 15);
		break;
	case 3:
		pPlayer = new Player("도적", 90, 12);
		break;
	}

	return pPlayer;
}
int GameController::selectFieldLevel()
{
	int iLevel = 0;
	cout << "1. 초급 사냥터" << endl;
	cout << "2. 중급 사냥터" << endl;
	cout << "3. 고급 사냥터" << endl;
	cout << "4. 뒤로가기" << endl << endl;
	cout << "사냥터를 선택하세요 >> ";
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