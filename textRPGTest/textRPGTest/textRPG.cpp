#include <iostream>

using namespace std;

typedef struct tCreature
{
	char szName[128];
	int iHP;
	int iPower;
}CREATURE;


CREATURE* createPlayer();
CREATURE* createMonster(int iSelect);
void renderCreature(CREATURE* pCreature);
void fight(CREATURE* pPlayer, CREATURE* pMonster);

int main()
{

	CREATURE* pPlayer = createPlayer();

	while(true)
	{
		system("cls");
		renderCreature(pPlayer);
		int iInput = 0;
		cout << "1. 사냥 2. 종료" << endl;
		cin >> iInput;

		if (2 == iInput)
		{
			break;
		}
		else if (1 == iInput)
		{
			while (true)
			{
				system("cls");
				renderCreature(pPlayer);
				int iLevel = 0;
				cout << "1. 초보맵" << endl;
				cout << "2. 중수맵" << endl;
				cout << "3. 고수맵" << endl;
				cout << "4. 뒤로가기" << endl;

				cin >> iLevel;
				
				if (4 == iLevel)
				{
					break;
				}
				else if (3 >= iLevel) {
					CREATURE* pMonster = createMonster(iLevel);
					fight(pPlayer, pMonster);
					delete(pMonster);
					pMonster = nullptr;
				}
			}
		}

	}
	delete(pPlayer);
	pPlayer = nullptr;
	return 0;
}

CREATURE* createPlayer()
{
	CREATURE* pPlayer = new CREATURE;
	int iSelect = 0;
	cout << "직업선택 1.전사 2.마법사 3. 도적 : ";
	cin >> iSelect;

	switch (iSelect)
	{
	case 1:
		strcpy_s(pPlayer->szName, "전사");
		pPlayer->iHP = 100;
		pPlayer->iPower = 30;
		break;
	case 2:
		strcpy_s(pPlayer->szName, "마법사");
		pPlayer->iHP = 100;
		pPlayer->iPower = 30;
		break;
	case 3:
		strcpy_s(pPlayer->szName, "도적");
		pPlayer->iHP = 100;
		pPlayer->iPower = 30;
		break;
	default:

		break;
	}

	return pPlayer;
}
CREATURE* createMonster(int Select)
{
	CREATURE* pMonster = new CREATURE;
	switch (Select)
	{
	case 1:
		strcpy_s(pMonster->szName, "초보몹");
		pMonster->iHP = 60;
		pMonster->iPower = 10;
		break;
	case 2:
		strcpy_s(pMonster->szName, "중수몹");
		pMonster->iHP = 70;
		pMonster->iPower = 20;
		break;
	case 3:
		strcpy_s(pMonster->szName, "고수몹");
		pMonster->iHP = 80;
		pMonster->iPower = 30;
		break;
	default:

		break;
	}

	return pMonster;
}

void renderCreature(CREATURE* pCreature)
{
	
	cout << pCreature->szName << endl;
	cout << "파워 : " << pCreature->iPower << "\t체력 :" << pCreature->iHP << endl;
	cout << "===================================" << endl;
}

void fight(CREATURE* pPlayer, CREATURE* pMonster)
{
	while (true)
	{
		system("cls");
		renderCreature(pPlayer);
		renderCreature(pMonster);
		int iSelect = 0;
		cout << "1.공격 2. 도망" << endl;
		cin >> iSelect;
		if (2 == iSelect)
		{
			break;
		}
		else if (1 == iSelect)
		{
			pPlayer->iHP -= pMonster->iPower;
			pMonster->iHP -= pPlayer->iPower;

			if (0 >= pPlayer->iHP)
			{
				pPlayer->iHP = 100;
				break;
			}
			if (0 >= pMonster->iHP)
			{
				break;
			}
		}
	}
}