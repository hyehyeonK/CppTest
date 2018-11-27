#include <iostream>

using namespace std;
const char fileName[128] = "CharacterInfo.txt";
typedef struct tCreature
{
	char szName[128];
	int iHP;
	int iOriginHP;
	int iPower;

}CREATURE;

CREATURE* createCharacter();
CREATURE* createMonster(int iLevel);
void RenderCreature(CREATURE* pCreature);
void fight(CREATURE* pCharacter, CREATURE* pMonster);
void saveData(CREATURE* pCharacter);
CREATURE* loadData();

int main()
{
	int iStart = 0;
	cout << "1.���� �����ϱ�\t2.�̾��ϱ� : ";
	cin >> iStart;
	CREATURE* pCharacter = nullptr;
	if (1 == iStart)
	{
		pCharacter = createCharacter();
	}
	else if (2 == iStart)
	{
		pCharacter = loadData();
		if (pCharacter == nullptr)
		{
			cout << "���̺� �����Ͱ� �����ϴ�. ĳ���͸� ���� �����մϴ�." << endl;
			system("pause");
			pCharacter = createCharacter();
		}
	}

	while (true)
	{
		system("cls");
		RenderCreature(pCharacter);
		int iInput = 0;
		cout << "1. �����\t2.���� : " << endl;
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
				RenderCreature(pCharacter);

				int iLevel = 0;
				cout << "1. �ʺ���\n2. �߼���\n3. �����\n4.�ڷΰ���" << endl;
				cin >> iLevel;
				CREATURE* pMonster = nullptr;

				if (4 == iLevel) {
					break;
				}
				pMonster = createMonster(iLevel);
				fight(pCharacter, pMonster);
				delete(pMonster);
				pMonster = nullptr;
			}

		}
	}
	saveData(pCharacter);
	delete(pCharacter);
	pCharacter = nullptr;
	return 0;
}

CREATURE* createCharacter()
{
	system("cls");

	CREATURE* pCharacter = new CREATURE;
	memset(pCharacter, 0, sizeof(CREATURE));

	int iSelect = 0;
	cout << "������ �����ϼ��� 1. ���� 2. ������ 3. ���� : ";
	cin >> iSelect;

	switch (iSelect)
	{
	case 1:
		strcpy_s(pCharacter->szName, "����");
		pCharacter->iHP = 100;
		pCharacter->iOriginHP = 100;
		pCharacter->iPower = 20;
		break;
	case 2:
		strcpy_s(pCharacter->szName, "������");
		pCharacter->iHP = 80;
		pCharacter->iOriginHP = 80;
		pCharacter->iPower = 30;
		break;
	case 3:
		strcpy_s(pCharacter->szName, "����");
		pCharacter->iHP = 90;
		pCharacter->iOriginHP = 90;
		pCharacter->iPower = 25;
		break;
	default:
		cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���." << endl;
		system("pause");
		return createCharacter();
		break;
	}
	return pCharacter;
}

CREATURE* createMonster(int iLevel)
{
	CREATURE* pMonster = new CREATURE;
	memset(pMonster, 0, sizeof(CREATURE));

	switch (iLevel)
	{
	case 1:
		strcpy_s(pMonster->szName, "�ʺ���");
		pMonster->iHP = 60;
		pMonster->iPower = 10;
		break;
	case 2:
		strcpy_s(pMonster->szName, "�߼���");
		pMonster->iHP = 80;
		pMonster->iPower = 20;
		break;
	case 3:
		strcpy_s(pMonster->szName, "�����");
		pMonster->iHP = 100;
		pMonster->iPower = 30;
		break;
	default:
		cout << "�߸��� �Է��Դϴ�." << endl;
		system("pause");
		break;
	}
	return pMonster;
}

void RenderCreature(CREATURE* pCreature)
{
	cout << "=====================" << pCreature->szName << "================" << endl;
	cout << "Power : " << pCreature->iPower << "\tHP : " << pCreature->iHP << endl;
	cout << "================================================" << endl;
}

void fight(CREATURE* pCharacter, CREATURE* pMonster)
{
	int iInput = 0;
	while (true) {
		system("cls");
		RenderCreature(pCharacter);
		RenderCreature(pMonster);

		cout << "1. ���� 2.���� : ";
		cin >> iInput;
		if (2 == iInput)
		{
			break;
		}
		else if (1 == iInput)
		{
			pCharacter->iHP -= pMonster->iPower;
			pMonster->iHP -= pCharacter->iPower;

			if (0 >= pCharacter->iHP)
			{
				pCharacter->iHP = pCharacter->iOriginHP;
				break;
			}
			if (0 >= pMonster->iHP)
			{
				break;
			}
		}
	}
}

void saveData(CREATURE* pCharacter)
{
	FILE* pFile = nullptr;
	fopen_s(&pFile, fileName, "wb");

	if (nullptr != pFile)
	{
		fwrite(pCharacter, sizeof(CREATURE), 1, pFile);
		fclose(pFile);
	}
}

CREATURE* loadData()
{
	FILE* pFile = nullptr;
	CREATURE* pCharacter = nullptr;
	fopen_s(&pFile, fileName, "rb");
	if (nullptr == pFile)
	{
		return nullptr;
	}
	pCharacter = new CREATURE;
	memset(pCharacter, 0, sizeof(CREATURE));
	fread_s(pCharacter, sizeof(CREATURE), sizeof(CREATURE), 1, pFile);
	fclose(pFile);

	return pCharacter;
}