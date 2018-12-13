#pragma once
#include "Item.h"
#include "Player.h"

class CStore
{
private:
	char m_szName[128];
	CItem* m_pItmes[3];
	CPlayer* m_pPlayer;

public:
	void SetPlayer(CPlayer* pPlayer);

public:
	void SelectStore();
	CItem* SaleItem();

public:
	void RenderItems() const;

public:
	CStore();
	~CStore();
};

