#pragma once
#include "Player.h"
#include "Store.h"
#include "Inventory.h"
#include "Field.h"

class CGameController
{
private:
	CObj*	m_pPlayer;
	CStore* m_pStore;
	CInventory* m_pInven;
	CField* m_pField;

public:
	void Initalize();
	void Progress();
	void Release();

private:
	void Inventory();

public:
	CGameController();
	~CGameController();
};

