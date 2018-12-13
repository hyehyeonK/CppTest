#pragma once
#include "Player.h"
#include "Field.h"

class GameController
{
public:
	void Init();
	void Play();

public:
	Player* CreatePlayer();
	Player* RoadData();
	void SaveData();
	Field* CreateField(Player* pPlayer);

public:
	explicit GameController();
	~GameController();

private:
	Player*		m_pPlayer;
	Field*		m_pField;
};