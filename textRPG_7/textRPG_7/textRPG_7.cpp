// textRPG_7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

