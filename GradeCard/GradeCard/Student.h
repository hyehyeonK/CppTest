#pragma once
#include "defineh.h"

class CStudent
{
private:
	char	m_szName[128];
	int		m_iScore[SbjCount];
	int		m_iTotal;
	float	m_iAvg;

public:
	void PrintInfo();

public:
	inline void SetName(char* _szName) { strcpy_s(m_szName, _szName); }
	inline char* GetName() { return m_szName; }
	void SetScore(int _iScore[SbjCount]);
	inline float GetAvg() { return m_iAvg; }
	inline int* GetScore() { return m_iScore; }
	void SetKor(int _iKor) { m_iScore[Kor] = _iKor; SetResult(); }
	void SetEng(int _iEng) { m_iScore[Eng] = _iEng; SetResult(); }
	void SetMath(int _iMath) { m_iScore[Math] = _iMath; SetResult(); }

private:
	void SetResult();

public:
	CStudent();
	CStudent(char* _szName, int _iKor, int _iEng, int _iMath);
	~CStudent();
};

