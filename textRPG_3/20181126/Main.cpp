// 20181126.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "GameController.h"


int main()
{
	//MainGameClass , PlayerClass, MonsterClass, FieldClass ���

	GameController CGame;
	CGame.init();

	if (!CGame.Play())
	{
		system("cls");
		cout << " ������ �����մϴ�." << endl;
	}

    return 0;
}

