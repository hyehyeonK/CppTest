// TextRPG_6.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "GameController.h"

int main()
{
	CGameController* pGameController = new CGameController();

	pGameController->Initalize();
	pGameController->Progress();
	pGameController->Release();

	SAFE_DELETE(pGameController);

    return 0;
}

