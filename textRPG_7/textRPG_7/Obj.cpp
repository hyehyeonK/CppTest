#include "stdafx.h"
#include "Obj.h"

void CObj::SetDamage(int _iPower)
{
	m_iHp -= _iPower;
}

void CObj::RenderInfo() const
{
	cout << "================< " << m_strName << " >================" << endl;
	cout << "Power : " << m_iPower << "\tHP : " << m_iHp << endl;
}

CObj::CObj()
{
}

CObj::CObj(string _strName, int _iPower, int _iHP, int _iMoney)
	:m_strName(_strName), m_iPower(_iPower), m_iHp(_iHP), m_iMoney(_iMoney)
{
}

CObj::~CObj()
{
}
