// textRPG_4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "GameController.h"

int main()
{
	GameController* pGame = new GameController();
	pGame->Init();
	pGame->Play();
    return 0;
}

