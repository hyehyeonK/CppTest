#include "stdafx.h"
#include "Store.h"
#include "Weapone.h"
#include "Armor.h"

CStore::CStore()
	:m_szName("")
{
		m_pItmes[0] = nullptr;
}

CStore::~CStore()
{
}

void CStore::SetPlayer(CPlayer * pPlayer)
{
	m_pPlayer = pPlayer;
}

void CStore::SelectStore()
{
	int iSelect = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		cout << "1. 무기 \t2. 방어구" << endl;
		cout << "상점을 선택하세요 : ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			strcpy_s(m_szName, "무기 상점");
			m_pItmes[0] = new CWeapone("초급 무기", ITEM_TYPE_WEAPONE, 50, 10);
			m_pItmes[1] = new CWeapone("중급 무기", ITEM_TYPE_WEAPONE, 100, 20);
			m_pItmes[2] = new CWeapone("고급 무기", ITEM_TYPE_WEAPONE, 200, 30);
			return;

		case 2:
			strcpy_s(m_szName, "방어구 상점");
			m_pItmes[0] = new CArmor("초급 방어구", ITEM_TYPE_ARMOR , 50, 10);
			m_pItmes[1] = new CArmor("중급 방어구", ITEM_TYPE_ARMOR, 100, 20);
			m_pItmes[2] = new CArmor("고급 방어구", ITEM_TYPE_ARMOR, 200, 30);
			return;

		default:
			cout << "잘못된 선택입니다." << endl;
			system("pause");
			break;
		}
	}
}

CItem * CStore::SaleItem()
{
	int iSelect = 0;
	CItem* pItem = nullptr;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		cout << endl;
		RenderItems();
		cout << "\n무엇을 사시겠습니까? (0.나가기) : ";
		cin >> iSelect;

		if (0 == iSelect) break;
		if (4 > iSelect)
		{
			pItem = m_pItmes[iSelect - 1];
			if (m_pPlayer->SpendMoney(pItem->GetPrice()))
			{
				if (ITEM_TYPE_WEAPONE == pItem->GetType()) 
					m_pPlayer->SetWeapone(pItem);

				else if (ITEM_TYPE_ARMOR == pItem->GetType())
					m_pPlayer->SetArmor(pItem);
			}
			else
			{
				cout << "*************** 소지금이 부족합니다. *************" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "잘못된 선택입니다." << endl;
			system("pause");
		}
	}
	return pItem;
}

void CStore::RenderItems() const
{
	cout << "=============" << m_szName << "=============" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << '\n' << (i + 1) << ". ";
		m_pItmes[i]->RenderInfo();
	}
}
