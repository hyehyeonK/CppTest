#include "stdafx.h"
#include "Store.h"
#include "define.h"

CStore::CStore(CObj* _pPlayer, CInventory* _pInven)
	:m_pPlayer(_pPlayer), m_pInven(_pInven)
{
}

CStore::~CStore()
{
}

void CStore::Progress()
{
	int iSelect = 0;
	int iType = 0;
	while (true)
	{
		iType = SelectStore();
		if (MENU_BACK == iType) { break; }
		SetItems(iType);

		while (true)
		{
			system("cls");
			m_pPlayer->RenderInfo();
			m_pInven->DrawList();
			DrawStore();
			cout << "무엇을 구매 하시겠습니까? (0.나가기) : ";
			cin >> iSelect;

			if (MENU_BACK == iSelect) { break; }

			if (0 < iSelect && 3 >= iSelect)
			{
				BuyItem(iType, *m_pItems[iSelect - 1]);
			}
			else
			{
				cout << "\n****잘못 된 입력 입니다.****\n" << endl;
				system("pause");
			}
		}

		ReleaseItems();
	}
	
}

int CStore::SelectStore()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->RenderInfo();
		cout << "\n===============< STORE >=================" << endl;
		cout << " 0. 뒤로가기\t 1. 무기상점\t2. 방어구상점 : ";
		cin >> iInput;

		if (0 <= iInput && 3 > iInput)
			break;
		else
		{
			cout << "\n****잘못 된 입력 입니다.****\n" << endl;
			system("pause");
		}
	}

	return iInput;
}

void CStore::SetItems(int iType)
{
	switch (iType)
	{
	case ITEM_WEAPON:
		strName = "무기상점";
		m_pItems[0] = new CWeapon(ITEM_WEAPON, "초급무기", 500, 10);
		m_pItems[1] = new CWeapon(ITEM_WEAPON, "중급무기", 1000, 15);
		m_pItems[2] = new CWeapon(ITEM_WEAPON, "고급무기", 2000, 20);
		break;

	case ITEM_ARMOR:
		strName = "방어구상점";
		m_pItems[0] = new CArmor(ITEM_ARMOR, "초급방어구", 500, 10);
		m_pItems[1] = new CArmor(ITEM_ARMOR, "중급방어구", 1000, 20);
		m_pItems[2] = new CArmor(ITEM_ARMOR, "고급방어구", 2000, 30);
		break;
	}

}

void CStore::DrawStore() const
{
	cout << "\n=============<" << strName << " >================" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << (i + 1) << ".";
		m_pItems[i]->DrawItem();
		cout << endl;
	}
}

void CStore::ReleaseItems()
{
	for (int i = 0; i < 3; ++i)
	{
		SAFE_DELETE(m_pItems[i]);
	}
}

void CStore::BuyItem(int iType, CItem & pItem)
{
	CItem* pTemp = nullptr;
	switch (iType)
	{
	case ITEM_ARMOR:
		pTemp = new CArmor(pItem);
		break;
	case ITEM_WEAPON:
		pTemp = new CWeapon(pItem);
		break;
	}

	int iPrice = pTemp->GetPrice();
	if (m_pPlayer->SpendMoney(iPrice))
	{
		m_pInven->Add(pTemp);
	}
	else
	{
		cout << "\n*****소지금이 부족합니다.*****\n" << endl;
		system("pause");
	}
}

