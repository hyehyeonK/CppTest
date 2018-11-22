// 20181121.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		cout << "1. ����� \t2.���� : ";
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
				cout << "1. �ʺ� ��\n2. �߼� ��\n3.��� ��\n4.�ڷΰ���" << endl;
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
	cout << "������ �����ϼ���.(1.����\t2.������\t3.����) : ";
	cin >> iSelect;

	Creature* pCharacter = nullptr;

	switch (iSelect)
	{
		case 1:
			pCharacter = new Creature("����", 100, 20);
			break;
		case 2:
			pCharacter = new Creature("������", 80, 30);
			break;
		case 3:
			pCharacter = new Creature("����", 90, 25);
			break;
		default:
			cout << "�߸� �Է� �ϼ̽��ϴ�." << endl;
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
			pMonster = new Creature("�ʺ���", 50, 10);
			break;
		case 2:
			pMonster = new Creature("�߼���", 80, 20);
			break;
		case 3:
			pMonster = new Creature("�����", 100, 30);
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

		cout << "1. ���\t2. ����" << endl;
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
