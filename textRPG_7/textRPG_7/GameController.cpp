#include "stdafx.h"
#include "GameController.h"
#include "define.h"

CGameController::CGameController()
	:m_pPlayer(nullptr)
	,m_pStore(nullptr)
	,m_pInven(nullptr)
	,m_pField(nullptr)
{
}

CGameController::~CGameController()
{
}

void CGameController::Initialize()
{
	m_pPlayer = new CPlayer();
	dynamic_cast<CPlayer*>(m_pPlayer)->SelectJob();
	m_pInven = new CInventory();
}

void CGameController::Progress()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		DrawMenu();
		cin >> iInput;

		if (MENU_EXIT == iInput)
			break;

		switch (iInput)
		{
		case MENU_HUNT:
			m_pField = new CField;
			m_pField->SetPlayer(m_pPlayer);
			m_pField->Progress();
			SAFE_DELETE(m_pField);
			break;

		case MENU_STORE:
			m_pStore = new CStore();
			m_pStore->SetPlayer(m_pPlayer);
			m_pStore->SetInven(m_pInven);
			m_pStore->Progress();
			SAFE_DELETE(m_pStore);
			break;

		case MENU_INVEN:
			ManageInven();
			break;

		default:
			REJECT_INPUT
			break;
		}
	}
}

void CGameController::Release()
{
	SAFE_DELETE(m_pInven);
	SAFE_DELETE(m_pPlayer);
}

void CGameController::DrawMenu() const
{
	cout << "\n================< MENU >================" << endl;
	cout << "1.사냥터\t2. 상점 \t3. 인벤토리\t4. 종료 : ";
}

void CGameController::ManageInven()
{
	int iSelect = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		m_pInven->DrawInventory();

		if (m_pInven->isEmpty())
		{
			cout << "\n*** 장착 가능한 장비가 없습니다. ***\n" << endl;
			system("pause");
			break;
		}

		cout << "장착할 장비를 선택하시오. (0.뒤로가기) : ";
		cin >> iSelect;

		if (INPUT_BACK == iSelect)
			break;

		--iSelect;
		CItem* pTemp = m_pInven->GetItem(iSelect);

		if (nullptr == pTemp)
		{
			REJECT_INPUT
		}
		else
		{
			const char* szType = typeid(*pTemp).name();

			if (!strcmp(szType, "class CArmor"))
			{
				CItem* pBuff = dynamic_cast<CPlayer*>(m_pPlayer)->GetArmor();

				dynamic_cast<CPlayer*>(m_pPlayer)->SetArmor(pTemp);
				m_pInven->DeleteItem(iSelect);

				if (nullptr != pBuff)
				{
					m_pInven->AddItem(pBuff);
				}
			}
			else if (!strcmp(szType, "class CWeapon"))
			{
				CItem* pBuff = dynamic_cast<CPlayer*>(m_pPlayer)->GetWeapon();

				dynamic_cast<CPlayer*>(m_pPlayer)->SetWeapon(pTemp);
				m_pInven->DeleteItem(iSelect);

				if (nullptr != pBuff)
				{
					m_pInven->AddItem(pBuff);
				}
			}
		}
	}
}
