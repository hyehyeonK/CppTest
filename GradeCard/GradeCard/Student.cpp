#include "stdafx.h"
#include "Student.h"


void CStudent::PrintInfo()
{
	cout << m_szName;
	for (int i = 0; i < SbjCount; ++i)
	{
		cout <<  '\t' << m_iScore[i];
	}
	cout << '\t' << m_iTotal << '\t' << m_iAvg;
	cout << endl;
}

void CStudent::SetScore(int _iScore[SbjCount])
{
	for (int i = 0; i < SbjCount; ++i)
	{
		m_iScore[i] = _iScore[i];
	}
	SetResult();
}

void CStudent::SetResult()
{
	m_iTotal = 0;
	for (int i = 0; i < SbjCount; ++i)
	{
		m_iTotal += m_iScore[i];
	}
	m_iAvg = (float)m_iTotal / SbjCount;
}

CStudent::CStudent()
{
	memset(m_szName, 0, sizeof(m_szName));
	memset(m_iScore, 0, sizeof(m_iScore));
}

CStudent::CStudent(char * _szName, int _iKor, int _iEng, int _iMath)
{
	strcpy_s(m_szName, _szName);
	m_iScore[Kor] = _iKor;
	m_iScore[Eng] = _iEng;
	m_iScore[Math] = _iMath;

	SetResult();
}


CStudent::~CStudent()
{
}
