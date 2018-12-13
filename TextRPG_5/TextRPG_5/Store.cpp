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
		cout << "1. ���� \t2. ��" << endl;
		cout << "������ �����ϼ��� : ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			strcpy_s(m_szName, "���� ����");
			m_pItmes[0] = new CWeapone("�ʱ� ����", ITEM_TYPE_WEAPONE, 50, 10);
			m_pItmes[1] = new CWeapone("�߱� ����", ITEM_TYPE_WEAPONE, 100, 20);
			m_pItmes[2] = new CWeapone("��� ����", ITEM_TYPE_WEAPONE, 200, 30);
			return;

		case 2:
			strcpy_s(m_szName, "�� ����");
			m_pItmes[0] = new CArmor("�ʱ� ��", ITEM_TYPE_ARMOR , 50, 10);
			m_pItmes[1] = new CArmor("�߱� ��", ITEM_TYPE_ARMOR, 100, 20);
			m_pItmes[2] = new CArmor("��� ��", ITEM_TYPE_ARMOR, 200, 30);
			return;

		default:
			cout << "�߸��� �����Դϴ�." << endl;
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
		cout << "\n������ ��ðڽ��ϱ�? (0.������) : ";
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
				cout << "*************** �������� �����մϴ�. *************" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "�߸��� �����Դϴ�." << endl;
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
