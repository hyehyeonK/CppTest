// textRPG_7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "GameController.h"

int main()
{
	CGameController* GameController = new CGameController;

	GameController->Initialize();
	GameController->Progress();
	GameController->Release();

	SAFE_DELETE(GameController);

    return 0;
}

