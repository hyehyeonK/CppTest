// TextRPG_6.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

