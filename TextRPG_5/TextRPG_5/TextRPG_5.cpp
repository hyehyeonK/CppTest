// TextRPG_5.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "GameController.h"

int main()
{
	CGameController* Game = new CGameController();
	Game->Initalize();
	Game->Progress();

	SAFE_DELETE(Game);
    return 0;
}

