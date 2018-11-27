// 20181126.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "GameController.h"


int main()
{
	//MainGameClass , PlayerClass, MonsterClass, FieldClass 사용

	GameController CGame;
	CGame.init();

	if (!CGame.Play())
	{
		system("cls");
		cout << " 게임을 종료합니다." << endl;
	}

    return 0;
}

