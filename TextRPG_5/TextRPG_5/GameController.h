#pragma once
#include "Player.h"
#include "Store.h"
#include "Field.h"

class CGameController
{
private:
	CPlayer* m_pPlayer;
	CStore*	 m_pStore;
	CField*	 m_pField;
public:
	void Initalize();
	void Progress();

public:
	CPlayer* CreatePlayer();
public:
	CGameController();
	~CGameController();
};

