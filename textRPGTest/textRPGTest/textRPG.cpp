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
		cout << "1. ��� 2. ����" << endl;
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
				cout << "1. �ʺ���" << endl;
				cout << "2. �߼���" << endl;
				cout << "3. �����" << endl;
				cout << "4. �ڷΰ���" << endl;

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
	cout << "�������� 1.���� 2.������ 3. ���� : ";
	cin >> iSelect;

	switch (iSelect)
	{
	case 1:
		strcpy_s(pPlayer->szName, "����");
		pPlayer->iHP = 100;
		pPlayer->iPower = 30;
		break;
	case 2:
		strcpy_s(pPlayer->szName, "������");
		pPlayer->iHP = 100;
		pPlayer->iPower = 30;
		break;
	case 3:
		strcpy_s(pPlayer->szName, "����");
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
		strcpy_s(pMonster->szName, "�ʺ���");
		pMonster->iHP = 60;
		pMonster->iPower = 10;
		break;
	case 2:
		strcpy_s(pMonster->szName, "�߼���");
		pMonster->iHP = 70;
		pMonster->iPower = 20;
		break;
	case 3:
		strcpy_s(pMonster->szName, "�����");
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
	cout << "�Ŀ� : " << pCreature->iPower << "\tü�� :" << pCreature->iHP << endl;
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
		cout << "1.���� 2. ����" << endl;
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