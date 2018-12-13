#include "stdafx.h"
#include "GameController.h"

#define WARRIOR 1
#define WIZARD 2
#define THIEF 3

#define NEW_START 1
#define RESTART 2

const char FILENAME[15] = "SAVE_DATA.txt";

GameController::GameController()
{
}

GameController::~GameController()
{
}
void GameController::Init()
{
	m_pPlayer = nullptr;
	int iInput = 0;

	while (true)
	{
		system("cls");
		cout << "1. ���ν���\t2. �̾��ϱ� : ";
		cin >> iInput;

			switch (iInput)
			{
			case NEW_START:
				m_pPlayer = CreatePlayer();
				break;

			case RESTART:
				m_pPlayer = RoadData();
				if (nullptr == m_pPlayer)
				{
					cout << "�̾��� �� �ִ� ĳ���Ͱ� �����ϴ�. ���� �����մϴ�." << endl;
					system("pause");
					m_pPlayer = CreatePlayer();
				}
				break;
			default:
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���." << endl;
				system("pause");
				break;
		}
		if (nullptr != m_pPlayer)
		{
			break;
		}
	}
}
void GameController::Play()
{
	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		int iInput = 0;
		cout << "1. �����\t2. ����\t3. ���� : ";
		cin >> iInput;

		if (3 == iInput) { break; }
		else if (1 == iInput)
		{
			while (true)
			{
				m_pField = CreateField(m_pPlayer);
				if (nullptr == m_pField) { break; }
				else 
				{
					m_pField->createMonster();
					m_pField->Fight();
					SAFE_DELETE(m_pField);
				}
			}
		}
		else if (2 == iInput)
		{
			SaveData();
		}
		else 
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���." << endl;
			system("pause");
		}
	}
	

}

void GameController::SaveData()
{
	FILE* pFIle = nullptr;
	fopen_s(&pFIle, FILENAME, "wb");

	if (nullptr == pFIle)
	{
		cout << "���� ����." << endl;
		system("pause");
	}
	else
	{
		fwrite(m_pPlayer, sizeof(Player), 1, pFIle);
		fclose(pFIle);
		cout << "���� �Ϸ�." << endl;
		system("pause");
	}

}
Player* GameController::RoadData()
{
	Player* pPlayer = nullptr;

	FILE* pFIle = nullptr;
	fopen_s(&pFIle, FILENAME, "rb");

	if (nullptr == pFIle)
	{
		return nullptr;
	}
	else
	{
		pPlayer = new Player();
		fread_s(pPlayer, sizeof(Player), sizeof(Player), 1, pFIle);
		fclose(pFIle);
		return pPlayer;
	}
}
Player* GameController::CreatePlayer()
{
	Player* pPlayer = nullptr;
	int iInput = 0;

	while (true)
	{
		system("cls");
		cout << "1. ���� \t2. ������\t3. ����" << endl;
		cout << "������ �����ϼ��� : ";
		cin >> iInput;


		switch (iInput)
		{
			case WARRIOR:
				pPlayer = new Player("����", 100, 30);
				break;

			case WIZARD:
				pPlayer = new Player("������", 80, 40);
				break;

			case THIEF:
				pPlayer = new Player("����", 90, 35);
				break;

			default:
				cout << "�߸� �� �Է��Դϴ�. �ٽ� ���� �� �ּ���." << endl;
				system("pause");
				break;
		}

		if (nullptr != pPlayer)
		{
			break;
		}
	}
	return pPlayer;
}

Field* GameController::CreateField(Player* pPlayer)
{
	Field* pField = nullptr;
	int iLevel = 0;

	while (true)
	{
		system("cls");
		pPlayer->Render();
		cout << "1. �ʺ���" << endl;
		cout << "2. �߼���" << endl;
		cout << "3. �����" << endl;
		cout << "4. �ڷΰ���" << endl;
		cout << ">> ";
		cin >> iLevel;

		if (4 == iLevel)
		{
			break;
		}
		else if (1 <= iLevel && 4 > iLevel)
		{
			pField = new Field(iLevel, pPlayer);
			break;
		}
		else
		{
			cout << "�߸� �� �Է��Դϴ�. �ٽ� ���� �� �ּ���." << endl;
			system("pause");
		}
	}
	return pField;
}