#include "stdafx.h"
#include "GameController.h"
#include "define.h"

CGameController::CGameController()
	:m_pPlayer(nullptr), m_pStore(nullptr), m_pInven(nullptr), m_pField(nullptr)
{
}

CGameController::~CGameController()
{
}

void CGameController::Initalize()
{
	int iSelect = 0;
	while (true)
	{
		system("cls");
		cout << "1. 전사 \t2. 마법사\t3. 도적" << endl;
		cout << "직업을 선택하세요. :" << endl;
		cin >> iSelect;

		switch (iSelect)
		{
		case JOB_WARRIOR:
			m_pPlayer = new CPlayer("전사", 100, 20);
			break;

		case JOB_WIZARD:
			m_pPlayer = new CPlayer("마법사", 80, 30);
			break;

		case JOB_THIEF:
			m_pPlayer = new CPlayer("도적", 90, 25);
			break;

		default:
			cout << "\n****잘못 된 입력 입니다.****\n" << endl;
			system("pause");
			break;
		}

		if (nullptr != m_pPlayer)
		{
			m_pInven = new CInventory;
			break;
		}
	}
}

void CGameController::Progress()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		cout << "\n===============< MENU >=================" << endl;
		cout << "1.사냥터\t2. 상점 \t3. 인벤토리\t4. 종료 : ";
		cin >> iInput;

		if (MENU_EXIT == iInput) { break; }

		switch (iInput)
		{
		case MENU_HUNT:
			m_pField = new CField(m_pPlayer);
			m_pField->Progress();
			SAFE_DELETE(m_pField);
			break;

		case MENU_STORE:
			m_pStore = new CStore(m_pPlayer, m_pInven);
			m_pStore->Progress();
			SAFE_DELETE(m_pStore);
			break;

		case MENU_INVEN:
			Inventory();
			break;

		default:
			cout << "\n****잘못 된 입력 입니다.****\n" << endl;
			system("pause");
			break;
		}
	}
}

void CGameController::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pInven);
}

void CGameController::Inventory()
{
	int iSelect = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		m_pInven->DrawList();
		if (m_pInven->IsEmpty())
		{
			cout << "\n****장착 가능한 아이템이 없습니다.****\n" << endl;
			system("pause");
			break;
		}
		else
		{
			cout << "\n장착할 아이템을 선택하세요. (0.뒤로가기): ";
			cin >> iSelect;
			
			if (MENU_BACK == iSelect)
				break;

			--iSelect;

			CItem* pSelectItem = m_pInven->Get(iSelect);
			if (nullptr == pSelectItem)
			{
				cout << "\n****잘못 된 선택입니다.****\n" << endl;
				system("pause");
			}
			else
			{
				switch (pSelectItem->GetType())
				{
				case ITEM_ARMOR:
					if (nullptr != m_pPlayer->GetArmor())
					{
						m_pInven->Add(m_pPlayer->GetArmor());
					}
					m_pPlayer->SetArmor(pSelectItem);
					break;
				case ITEM_WEAPON:
					if (nullptr != m_pPlayer->GetWeapon())
					{
						m_pInven->Add(m_pPlayer->GetWeapon());
					}
					m_pPlayer->SetWeapon(pSelectItem);
					break;
				}
				m_pInven->DeleteNode(iSelect);
			}
		}
	}
}
