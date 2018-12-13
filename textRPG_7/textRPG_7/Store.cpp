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
		cout << "1. �������\t2. ������" << endl;
		cout << "\n����(0. �ڷΰ���) : ";
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
				cout << "������ �����Ͻðڽ��ϱ�? (0. �ڷΰ���) : ";
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
		m_strStoreName = "�������";
		m_pItems[0] = new CWeapon("�ʱ޹���", 500, 10);
		m_pItems[1] = new CWeapon("�߱޹���", 1000, 20);
		m_pItems[2] = new CWeapon("��޹���", 2000, 40);
		break;

	case ITEM_ARMOR:
		m_strStoreName = "������";
		m_pItems[0] = new CArmor("�ʱ޹�", 500, 10);
		m_pItems[1] = new CArmor("�߱޹�", 1000, 20);
		m_pItems[2] = new CArmor("��޹�", 2000, 30);
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
		cout << "\n*****�������� �����մϴ�.*****\n" << endl;
		system("pause");
	}
}
