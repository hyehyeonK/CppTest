// 20181121.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "creature.h"

Creature* createCharacter();
Creature* createMonster(int iSelect);
void fight(Creature* pCharacter, Creature* pMonster);

int main()
{
	Creature* pCharacter = createCharacter();
	while (true)
	{
		system("cls");
		(*pCharacter).printCreatureInfo();
		int iSelect = 0;
		cout << "1. 사냥터 \t2.종료 : ";
		cin >> iSelect;
		if (2 == iSelect)
		{
			break;
		}
		else if (1 == iSelect)
		{
			while (true) {
				system("cls");
				(*pCharacter).printCreatureInfo();
				int iLevel;
				cout << "1. 초보 맵\n2. 중수 맵\n3.고수 맵\n4.뒤로가기" << endl;
				cin >> iLevel;
				if (4 == iLevel)
				{
					break;
				}
				Creature *pMonster = createMonster(iLevel);
				fight(pCharacter, pMonster);
				delete(pMonster);
				pMonster = nullptr;
			}
			
		}
	}
	delete(pCharacter);
	pCharacter = nullptr;

	
    return 0;
}

Creature* createCharacter()
{
	system("cls");
	int iSelect = 0;
	cout << "직업을 선택하세요.(1.전사\t2.마법사\t3.도적) : ";
	cin >> iSelect;

	Creature* pCharacter = nullptr;

	switch (iSelect)
	{
		case 1:
			pCharacter = new Creature("전사", 100, 20);
			break;
		case 2:
			pCharacter = new Creature("마법사", 80, 30);
			break;
		case 3:
			pCharacter = new Creature("도적", 90, 25);
			break;
		default:
			cout << "잘못 입력 하셨습니다." << endl;
			system("pause");
			return createCharacter();
			break;
	}

	return pCharacter;
}
Creature* createMonster(int iSelect)
{
	Creature* pMonster = nullptr;
	switch (iSelect)
	{
		case 1:
			pMonster = new Creature("초보몹", 50, 10);
			break;
		case 2:
			pMonster = new Creature("중수몹", 80, 20);
			break;
		case 3:
			pMonster = new Creature("고수몹", 100, 30);
			break;
	}
	return pMonster;
}

void fight(Creature* pCharacter, Creature* pMonster)
{
	while (true)
	{
		system("cls");
		(*pCharacter).printCreatureInfo();
		(*pMonster).printCreatureInfo();
		int iSelect = 0;

		cout << "1. 사냥\t2. 도망" << endl;
		cin >> iSelect;

		if (2 == iSelect)
		{
			break;
		}
		else if (1 == iSelect)
		{
			(*pCharacter).attacked((*pMonster).getPower());
			(*pMonster).attacked((*pCharacter).getPower());

			if (0 >= (*pCharacter).getHP())
			{
				(*pCharacter).resurrectionCharacter();
				break;
			}

			if (0 >= (*pMonster).getHP())
			{
				break;
			}
		}
	}
	

}
