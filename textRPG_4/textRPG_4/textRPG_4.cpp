// textRPG_4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

