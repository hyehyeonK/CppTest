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
		cout << "1. �����\t2. ���� \t3. ���� : ";
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
			cout << "�߸��� �����Դϴ�." << endl;
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
		cout << "1. ���� \t2. ������\t3. ����" << endl;
		cout << "������ �����ϼ��� : ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			pPlayer = new CPlayer("����", 100, 20, 100);
			break;
		case 2:
			pPlayer = new CPlayer("������", 80, 30, 100);
			break;
		case 3:
			pPlayer = new CPlayer("����", 90, 25, 100);
			break;
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			system("pause");
			break;
		}

		if (pPlayer != nullptr)
			break;
	}
	return pPlayer;
}
