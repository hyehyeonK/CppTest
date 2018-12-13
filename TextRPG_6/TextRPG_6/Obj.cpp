#include "stdafx.h"
#include "Obj.h"

CObj::CObj()
{
}

CObj::CObj(string _strName, int _iHP, int _iPower, int _iMoney)
	:m_strName(_strName), m_iHP(_iHP), m_iPower(_iPower), m_iMoney(_iMoney)
{
}

CObj::~CObj()
{
}

void CObj::RenderInfo() const
{
	cout << "================================" << endl;
	cout << m_strName << endl;
	cout << "Power : " << m_iPower << "\tHP : " << m_iHP << endl;	
}
