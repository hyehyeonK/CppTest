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
	m_Vec.push_back(CStudent("���л�", 100, 80, 90));
	m_Vec.push_back(CStudent("���¾�", 70, 40, 80));
	m_Vec.push_back(CStudent("������", 50, 100, 70));
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
				cout << "\n*****��� �� �����Ͱ� �����ϴ�.*****\n" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "========<����ǥ ���>========\n" << endl;
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
	cout << "=====<����ǥ ����>=====" << endl;
	cout << "1. �߰�" << endl;
	cout << "2. ����" << endl;
	cout << "3. �˻�" << endl;
	cout << "4. ���" << endl;
	cout << "5. ����" << endl;
	cout << "6. ����" << endl;
	cout << "7. ����" << endl;
	cout << "======================" << endl;
	cout << "������ �Ͻðڽ��ϱ�?";
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
		cout << "========< �߰� >========" << endl;
		pNewStd = CStudent();
		memset(szInput, 0, sizeof(szInput));

		cout << "�̸� : ";
		cin >> szInput;
		pNewStd.SetName(szInput);

		while (true)
		{
			cout << "���� : ";
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
			cout << "���� : ";
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
			cout << "���� : ";
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
		cout << "�̸�\t����\t����\t����\t����\t���" << endl;
		m_Vec[m_Vec.size() - 1].PrintInfo();
		cout << "\n*******�����͸� �߰��߽��ϴ�.*******\n" << endl;
		cout << "0. �ڷΰ��� 1~. ��� �߰� ";
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
		cout << "\n========< ���� >========" << endl;

		if (m_Vec.empty())
		{
			cout << "\n*****���� �� �����Ͱ� �����ϴ�.*****\n" << endl;
			system("pause");
			return;
		}

		cout << "������ �л��� ��ȣ�� �Է��� �ּ���.(0.�ڷΰ���)" << endl;
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
			cout << "\n*******������ �Ϸ��߽��ϴ�.*******\n" << endl;
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
		cout << "=================< �˻� >=================" << endl;
		if (m_Vec.empty())
		{
			cout << "\n*****�˻� �� �����Ͱ� �����ϴ�.*****\n" << endl;
			system("pause");
			return;
		}

		char szInput[128];
		memset(szInput, 0, sizeof(szInput));

		cout << "�˻� �� �л��� �̸� (0.�ڷΰ���): ";
		cin >> szInput;
		if (!strcmp(szInput, "0"))
			break;

		for (size_t i = 0; i < m_Vec.size(); ++i)
		{
			if (0 == strcmp(m_Vec[i].GetName(), szInput))
			{
				isNoData = false;
				cout << "\n�̸�\t����\t����\t����\t����\t���" << endl;
				m_Vec[i].PrintInfo();
				cout << "========================================\n" << endl;
				system("pause");
				break;
			}
		}
		if (isNoData)
		{
			cout << "\n*****�����͸� ã�� �� �����ϴ�.*****\n" << endl;
			system("pause");
		}
	}
}

void CGradeTable::Print()
{
	cout << "\t�̸�\t����\t����\t����\t����\t���" << endl;
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
		cout << "========< ���� >========" << endl;
		if (m_Vec.empty())
		{
			cout << "\n*****���� �� �����Ͱ� �����ϴ�.*****\n" << endl;
			system("pause");
			return;
		}

		cout << "���� �� �л��� ��ȣ (0. �ڷΰ���): ";
		cin >> iInput;

		if (BACK == iInput) break;

		--iInput;
		iModi = 0;
		while (true)
		{
			system("cls");
			cout << "========< ���� >========" << endl;
			m_Vec.at(iInput).PrintInfo();
			if (SbjCount < iModi)
			{
				cout << "\n*****������ �Ϸ� �߽��ϴ�.*****\n" << endl;
				system("pause");
				break;
			}

			switch (iModi)
			{
			case Modi_Name:
				cout << "�̸� (n : �ǳ� �ٱ�) : ";
				cin >> szInput;
				if (strcmp(szInput,"n"))
				{
					m_Vec[iInput].SetName(szInput);
				}
				break;

			case Modi_Kor:
				cout << "���� ���� (n : �ǳ� �ٱ�) : ";
				cin >> szInput;
				if (strcmp(szInput, "n"))
				{
					m_Vec[iInput].SetKor(atoi(szInput));
				}
				break;

			case Modi_Eng:
				cout << "���� ���� (n : �ǳ� �ٱ�) : ";
				cin >> szInput;
				if (strcmp(szInput, "n"))
				{
					m_Vec[iInput].SetEng(atoi(szInput));
				}
				break;

			case Modi_Math:
				cout << "���� ���� (n : �ǳ� �ٱ�) : ";
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
		cout << "=================< ���� >=================" << endl;
		Print();
		if (m_Vec.empty())
		{
			cout << "\n*****���� �� �����Ͱ� �����ϴ�.*****\n" << endl;
			system("pause");
			return;
		}

		cout << "===========================================\n" << endl;
		cout << "������ ������ �����ϼ���." << endl;
		cout << "1.�̸� 2. ��� (0. �ڷΰ���) : ";
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
