#include "stdafx.h"
#include "Store.h"
#include "define.h"

CStore::CStore()
	:m_pPlayer(nullptr)
	,m_pInven(nullptr)
{
}

CStore::~CStore()
{
}

void CStore::SetPlayer(CObj * _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CStore::SetInven(CInventory * _pInven)
{
	m_pInven = _pInven;
}

void CStore::Progress()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		cout << "\n================< STORE >================" << endl;
		cout << "1. 무기상점\t2. 방어구상점" << endl;
		cout << "\n선택(0. 뒤로가기) : ";
		cin >> iInput;

		if (INPUT_BACK == iInput)
			break;

		if (ITEM_WEAPON == iInput || ITEM_ARMOR == iInput)
		{
			SetItems(iInput);
			int iSelect = 0;
			while (true)
			{
				system("cls");
				m_pPlayer->RenderInfo();
				m_pInven->DrawInventory();
				DrawItems();
				cout << "무엇을 구매하시겠습니까? (0. 뒤로가기) : ";
				cin >> iSelect;

				if (INPUT_BACK == iSelect)
					break;

				--iSelect;
				if (0 <= iSelect && ITEM_COUNT > iSelect)
				{
					BuyItem(m_pItems[iSelect]);
				}
				else 
				{
					REJECT_INPUT;
				}

				
			}

			ReleaseItems();
		}
		else
		{
			REJECT_INPUT
		}
	}
}

void CStore::SetItems(int _iType)
{
	switch (_iType)
	{
	case ITEM_WEAPON:
		m_strStoreName = "무기상점";
		m_pItems[0] = new CWeapon("초급무기", 500, 10);
		m_pItems[1] = new CWeapon("중급무기", 1000, 20);
		m_pItems[2] = new CWeapon("고급무기", 2000, 40);
		break;

	case ITEM_ARMOR:
		m_strStoreName = "방어구상점";
		m_pItems[0] = new CArmor("초급방어구", 500, 10);
		m_pItems[1] = new CArmor("중급방어구", 1000, 20);
		m_pItems[2] = new CArmor("고급방어구", 2000, 30);
		break;
	}
}

void CStore::ReleaseItems()
{
	for (int i = 0; i < ITEM_COUNT; ++i)
		SAFE_DELETE(m_pItems[i]);
}

void CStore::DrawItems()
{
	cout << "\n================< "<< m_strStoreName << " >================" << endl;
	for (int i = 0; i < ITEM_COUNT; ++i)
	{
		cout << (i + 1) << ". ";
		m_pItems[i]->Draw();
		cout << endl;
	}
}

void CStore::BuyItem(CItem* _pItem)
{
	CItem* pTemp = nullptr;

	if (typeid(CArmor) == typeid(*_pItem))
	{
		pTemp = new CArmor(*_pItem);
	}
	else if (typeid(CWeapon) == typeid(*_pItem))
	{
		pTemp = new CWeapon(*_pItem);
	}

	int iPrice = pTemp->GetPrice();
	
	if (dynamic_cast<CPlayer*>(m_pPlayer)->SpendMoney(iPrice))
	{
		m_pInven->AddItem(pTemp);
	}
	else
	{
		cout << "\n*****소지금이 부족합니다.*****\n" << endl;
		system("pause");
	}
}
