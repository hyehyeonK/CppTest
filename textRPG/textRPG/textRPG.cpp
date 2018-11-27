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
	cout << "1.새로 시작하기\t2.이어하기 : ";
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
			cout << "세이브 데이터가 없습니다. 캐릭터를 새로 생성합니다." << endl;
			system("pause");
			pCharacter = createCharacter();
		}
	}

	while (true)
	{
		system("cls");
		RenderCreature(pCharacter);
		int iInput = 0;
		cout << "1. 사냥터\t2.종료 : " << endl;
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
				cout << "1. 초보맵\n2. 중수맵\n3. 고수맵\n4.뒤로가기" << endl;
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
	cout << "직업을 선택하세요 1. 전사 2. 마법사 3. 도적 : ";
	cin >> iSelect;

	switch (iSelect)
	{
	case 1:
		strcpy_s(pCharacter->szName, "전사");
		pCharacter->iHP = 100;
		pCharacter->iOriginHP = 100;
		pCharacter->iPower = 20;
		break;
	case 2:
		strcpy_s(pCharacter->szName, "마법사");
		pCharacter->iHP = 80;
		pCharacter->iOriginHP = 80;
		pCharacter->iPower = 30;
		break;
	case 3:
		strcpy_s(pCharacter->szName, "도적");
		pCharacter->iHP = 90;
		pCharacter->iOriginHP = 90;
		pCharacter->iPower = 25;
		break;
	default:
		cout << "잘못된 입력입니다. 다시 선택해 주세요." << endl;
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
		strcpy_s(pMonster->szName, "초보몹");
		pMonster->iHP = 60;
		pMonster->iPower = 10;
		break;
	case 2:
		strcpy_s(pMonster->szName, "중수몹");
		pMonster->iHP = 80;
		pMonster->iPower = 20;
		break;
	case 3:
		strcpy_s(pMonster->szName, "고수몹");
		pMonster->iHP = 100;
		pMonster->iPower = 30;
		break;
	default:
		cout << "잘못된 입력입니다." << endl;
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

		cout << "1. 공격 2.도망 : ";
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