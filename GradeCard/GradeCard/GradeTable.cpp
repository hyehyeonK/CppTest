#include "stdafx.h"
#include "GradeTable.h"


CGradeTable::CGradeTable()
{
}


CGradeTable::~CGradeTable()
{
}

void CGradeTable::Init()
{
	m_Vec.push_back(CStudent("나학생", 100, 80, 90));
	m_Vec.push_back(CStudent("김태양", 70, 40, 80));
	m_Vec.push_back(CStudent("빛나리", 50, 100, 70));
}

void CGradeTable::Progress()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		PrintMenu();
		cin >> iInput;
		if (MENU_Exit == iInput) break;

		switch (iInput)
		{
		case MENU_Add:
			Add();
			break;

		case MENU_Delete:
			Delete();
			break;

		case MENU_Search:
			Search();
			break;

		case MENU_Print:
			if (m_Vec.empty())
			{
				cout << "\n*****출력 할 데이터가 없습니다.*****\n" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "========<성적표 출력>========\n" << endl;
				Print();
				cout << "\n============================" << endl;
				system("pause");
			}
			break;

		case MENU_Modi:
			Modify();
			break;

		case MENU_Sort:
			Sort();
			break;

		default:
			REJECT_INPUT
			break;
		}
	}
}

void CGradeTable::PrintMenu()
{
	cout << "=====<성적표 관리>=====" << endl;
	cout << "1. 추가" << endl;
	cout << "2. 삭제" << endl;
	cout << "3. 검색" << endl;
	cout << "4. 출력" << endl;
	cout << "5. 수정" << endl;
	cout << "6. 정렬" << endl;
	cout << "7. 종료" << endl;
	cout << "======================" << endl;
	cout << "무엇을 하시겠습니까?";
}

void CGradeTable::Add()
{
	CStudent pNewStd;
	int iScore[SbjCount];
	int iInput;
	char szInput[128];

	while (true)
	{
		system("cls");
		cout << "========< 추가 >========" << endl;
		pNewStd = CStudent();
		memset(szInput, 0, sizeof(szInput));

		cout << "이름 : ";
		cin >> szInput;
		pNewStd.SetName(szInput);

		while (true)
		{
			cout << "국어 : ";
			cin >> szInput;
			if (100 >= atoi(szInput))
			{
				iScore[Kor] = atoi(szInput);
				break;
			}
			else
			{
				REJECT_INPUT
			}
		}
		while (true)
		{
			cout << "영어 : ";
			cin >> szInput;
			if (100 >= atoi(szInput))
			{
				iScore[Eng] = atoi(szInput);
				break;
			}
			else
			{
				REJECT_INPUT
			}
		}
		
		while (true)
		{
			cout << "수학 : ";
			cin >> szInput;
			if (100 >= atoi(szInput))
			{
				iScore[Math] = atoi(szInput);
				break;
			}
			else
			{
				REJECT_INPUT
			}
		}
		
		pNewStd.SetScore(iScore);
		m_Vec.push_back(pNewStd);

		cout << "===============================" << endl << endl;
		cout << "이름\t국어\t영어\t수학\t총점\t평균" << endl;
		m_Vec[m_Vec.size() - 1].PrintInfo();
		cout << "\n*******데이터를 추가했습니다.*******\n" << endl;
		cout << "0. 뒤로가기 1~. 계속 추가 ";
		cin >> iInput;
		if (BACK == iInput) break;
	}
}

void CGradeTable::Delete()
{
	int iIndex = 0;

	while (true)
	{
		system("cls");

		Print();
		cout << "\n========< 삭제 >========" << endl;

		if (m_Vec.empty())
		{
			cout << "\n*****삭제 할 데이터가 없습니다.*****\n" << endl;
			system("pause");
			return;
		}

		cout << "삭제할 학생의 번호를 입력해 주세요.(0.뒤로가기)" << endl;
		cin >> iIndex;

		if (BACK == iIndex) break;

		if (m_Vec.size() < iIndex || 0 > iIndex)
		{
			REJECT_INPUT;
		}
		else
		{
			--iIndex;
			m_Vec.erase(m_Vec.begin() + iIndex);
			cout << "\n*******삭제를 완료했습니다.*******\n" << endl;
			system("pause");
		}
	}	
}

void CGradeTable::Search()
{
	bool isNoData = true;

	while (true)
	{
		system("cls");
		cout << "=================< 검색 >=================" << endl;
		if (m_Vec.empty())
		{
			cout << "\n*****검색 할 데이터가 없습니다.*****\n" << endl;
			system("pause");
			return;
		}

		char szInput[128];
		memset(szInput, 0, sizeof(szInput));

		cout << "검색 할 학생의 이름 (0.뒤로가기): ";
		cin >> szInput;
		if (!strcmp(szInput, "0"))
			break;

		for (size_t i = 0; i < m_Vec.size(); ++i)
		{
			if (0 == strcmp(m_Vec[i].GetName(), szInput))
			{
				isNoData = false;
				cout << "\n이름\t국어\t영어\t수학\t총점\t평균" << endl;
				m_Vec[i].PrintInfo();
				cout << "========================================\n" << endl;
				system("pause");
				break;
			}
		}
		if (isNoData)
		{
			cout << "\n*****데이터를 찾을 수 없습니다.*****\n" << endl;
			system("pause");
		}
	}
}

void CGradeTable::Print()
{
	cout << "\t이름\t국어\t영어\t수학\t총점\t평균" << endl;
	if (m_Vec.empty()) 
	{
		cout << "\t\t+++( No Data )+++" << endl;
		return;
	}
	for (size_t i = 0; i < m_Vec.size(); ++i)
	{
		cout << (i + 1) << ".\t";
		m_Vec[i].PrintInfo();
	}
}

void CGradeTable::Modify()
{
	int iInput = 0;
	char szInput[128];
	int iScore;
	int iModi;
	while (true)
	{
		system("cls");
		Print();
		cout << "========< 수정 >========" << endl;
		if (m_Vec.empty())
		{
			cout << "\n*****수정 할 데이터가 없습니다.*****\n" << endl;
			system("pause");
			return;
		}

		cout << "수정 할 학생의 번호 (0. 뒤로가기): ";
		cin >> iInput;

		if (BACK == iInput) break;

		--iInput;
		iModi = 0;
		while (true)
		{
			system("cls");
			cout << "========< 수정 >========" << endl;
			m_Vec.at(iInput).PrintInfo();
			if (SbjCount < iModi)
			{
				cout << "\n*****수정을 완료 했습니다.*****\n" << endl;
				system("pause");
				break;
			}

			switch (iModi)
			{
			case Modi_Name:
				cout << "이름 (n : 건너 뛰기) : ";
				cin >> szInput;
				if (strcmp(szInput,"n"))
				{
					m_Vec[iInput].SetName(szInput);
				}
				break;

			case Modi_Kor:
				cout << "국어 점수 (n : 건너 뛰기) : ";
				cin >> szInput;
				if (strcmp(szInput, "n"))
				{
					m_Vec[iInput].SetKor(atoi(szInput));
				}
				break;

			case Modi_Eng:
				cout << "영어 점수 (n : 건너 뛰기) : ";
				cin >> szInput;
				if (strcmp(szInput, "n"))
				{
					m_Vec[iInput].SetEng(atoi(szInput));
				}
				break;

			case Modi_Math:
				cout << "수학 점수 (n : 건너 뛰기) : ";
				cin >> szInput;
				if (strcmp(szInput, "n"))
				{
					m_Vec[iInput].SetMath(atoi(szInput));
				}
				break;
			}

			++iModi;
		}
	}	
}

void CGradeTable::Sort()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		cout << "=================< 정렬 >=================" << endl;
		Print();
		if (m_Vec.empty())
		{
			cout << "\n*****정렬 할 데이터가 없습니다.*****\n" << endl;
			system("pause");
			return;
		}

		cout << "===========================================\n" << endl;
		cout << "정렬할 기준을 선택하세요." << endl;
		cout << "1.이름 2. 평균 (0. 뒤로가기) : ";
		cin >> iInput;

		if (BACK == iInput) break;

		int last = 0;
		switch (iInput)
		{
		case Sort_Name:
			for (size_t i = 1; i < m_Vec.size(); ++i)
			{
				last = m_Vec.size() - i;
				for (int j = 0; j < last; ++j)
				{
					if (0 < strcmp(m_Vec[j].GetName(),m_Vec[j + 1].GetName()))
					{
						CStudent temp = m_Vec[j];
						m_Vec[j] = m_Vec[j + 1];
						m_Vec[j + 1] = temp;
					}
				}
			}
			break;

		case Sort_Avg:
			for (size_t i = 1; i < m_Vec.size(); ++i)
			{
				last = m_Vec.size() - i;
				for (int j = 0; j < last; ++j)
				{
					if (m_Vec[j].GetAvg() < m_Vec[j + 1].GetAvg())
					{
						CStudent temp = m_Vec[j];
						m_Vec[j] = m_Vec[j + 1];
						m_Vec[j + 1] = temp;
					}
				}
			}
			break;
		default:
			REJECT_INPUT
				break;
		}
	}
}
