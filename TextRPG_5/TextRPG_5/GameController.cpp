#include "stdafx.h"
#include "GameController.h"


CGameController::CGameController()
{
}


CGameController::~CGameController()
{
}

void CGameController::Initalize()
{
	m_pPlayer = CreatePlayer();
}

void CGameController::Progress()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		cout << "1. 사냥터\t2. 상점 \t3. 종료 : ";
		cin >> iInput;

		if (3 == iInput) break;

		switch (iInput)
		{
		case 1:
			m_pField = new CField(m_pPlayer);
			m_pField->Progress();
			break;

		case 2:
			m_pStore = new CStore();
			m_pStore->SetPlayer(m_pPlayer);
			m_pStore->SelectStore();
			m_pStore->SaleItem();
			break;

		default:
			cout << "잘못된 선택입니다." << endl;
			system("pause");
			break;
		}
	}
}

CPlayer* CGameController::CreatePlayer()
{
	CPlayer* pPlayer = nullptr;

	int iSelect = 0;

	while (true)
	{
		system("cls");
		cout << "1. 전사 \t2. 마법사\t3. 도적" << endl;
		cout << "직업을 선택하세요 : ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			pPlayer = new CPlayer("전사", 100, 20, 100);
			break;
		case 2:
			pPlayer = new CPlayer("마법사", 80, 30, 100);
			break;
		case 3:
			pPlayer = new CPlayer("도적", 90, 25, 100);
			break;
		default:
			cout << "잘못된 선택입니다." << endl;
			system("pause");
			break;
		}

		if (pPlayer != nullptr)
			break;
	}
	return pPlayer;
}
