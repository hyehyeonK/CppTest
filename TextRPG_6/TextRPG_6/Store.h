#pragma once
#include "Player.h"
#include "Armor.h"
#include "Weapon.h"
#include "Inventory.h"

class CStore
{
private:
	string	strName;
	CObj*	m_pPlayer;
	CItem*	m_pItems[3];
	CInventory* m_pInven;

private:
	int SelectStore();
	void SetItems(int iType);
	void DrawStore() const;
	void ReleaseItems();
	void BuyItem(int iType, CItem& pItem);
	//void ReSell(CItem);

public:
	void Progress();

public:
	CStore(CObj* _pPlayer, CInventory* _pInven);
	~CStore();
};

