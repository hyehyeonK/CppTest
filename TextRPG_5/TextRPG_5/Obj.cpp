#include "stdafx.h"
#include "Obj.h"



CObj::CObj()
{
}

CObj::CObj(char * szName, int iHP, int iPower)
	:m_iHP(iHP), m_iPower(iPower)
{
	strcpy_s(m_szName, szName);
}


CObj::~CObj()
{
}

void CObj::Damaged(int iPower)
{
	m_iHP -= iPower;
}

void CObj::RenderInfo() const
{
	cout << "=========================================" << endl;
	cout << "< " << m_szName << " >" << endl;
	cout << "Power : " << m_iPower << "\tHP : " << m_iHP << endl;
}
