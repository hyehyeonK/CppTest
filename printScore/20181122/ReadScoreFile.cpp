#include <iostream>

using namespace std;

typedef struct tagStudent
{
	char szName[128];
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;

}STUDENT;

int main()
{
	const int iNum = 3;
	const char FileName[128] = "Students.txt";
	FILE* pFile = nullptr;

	fopen_s(&pFile, FileName, "wt");
	if (nullptr == pFile)
	{
		fputs("파일 개방 실패", stdout);
	}

	for (int i = 0; i < iNum; ++i)
	{
		STUDENT tStudent;
		memset(&tStudent, 0, sizeof(STUDENT));

		cout << "이름 : ";
		cin >> tStudent.szName;
		cout << "국어 : ";
		cin >> tStudent.iKor;
		cout << "영어 : ";
		cin >> tStudent.iEng;
		cout << "수학 : ";
		cin >> tStudent.iMath;

		tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
		tStudent.fAvg = (float)tStudent.iTotal / iNum;

		fwrite(&tStudent, sizeof(STUDENT), 1, pFile);
	}

	fclose(pFile);
	pFile = nullptr;

	cout << "====================================" << endl;
	cout << "이름\t국어\t영어\t수학\t총점\t평균" << endl;

	fopen_s(&pFile, FileName, "rt");

	STUDENT tStudentList[iNum];
	memset(tStudentList, 0, sizeof(STUDENT) * iNum);
	fread(tStudentList, sizeof(STUDENT), 3, pFile);

	for (int i = 0; i < iNum; ++i)
	{
		cout << tStudentList[i].szName << '\t' << tStudentList[i].iKor << '\t' << tStudentList[i].iEng << '\t' << tStudentList[i].iMath << '\t'
			<< tStudentList[i].iTotal << '\t' << tStudentList[i].fAvg << endl;
	}

	return 0;
}