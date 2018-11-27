#pragma once

#include "Player.h"
#include "Monster.h"
#include "Field.h"


class GameController
{
private:

	Player*		m_pPlayer;
	Field*		m_pField;

public:
	void init();
	int selectCharacter();
	Player* createPlayer(int iSelect);
	int selectFieldLevel();
	Field* createField(int iLevel);
	bool Play();


};