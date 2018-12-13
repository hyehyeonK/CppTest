#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster(char * szName, int iHP, int iPower, int iCoin)
	:CObj(szName, iHP, iPower), m_iCoin(iCoin)
{
}

CMonster::CMonster()
	:m_iCoin(0)
{
}


CMonster::~CMonster()
{
}
