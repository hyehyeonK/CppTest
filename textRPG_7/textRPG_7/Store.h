#pragma once
#include "Weapon.h"
#include "Armor.h"
#include "Player.h"
#include "Inventory.h"

class CStore
{
private:
	static const int ITEM_COUNT = 3;
	string		 m_strStoreName;
	CItem*		 m_pItems[ITEM_COUNT];
	CObj*		 m_pPlayer;
	CInventory*	 m_pInven;

public :
	void SetPlayer(CObj* _pPlayer);
	void SetInven(CInventory* _pInven);
	void Progress();

private :
	void SetItems(int _iType);
	void ReleaseItems();
	void DrawItems();
	void BuyItem(CItem* _pItem);

public:
	CStore();
	~CStore();
};

