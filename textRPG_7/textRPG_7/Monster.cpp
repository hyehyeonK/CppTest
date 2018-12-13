#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}

CMonster::CMonster(string _strName, int _iPower, int _iHP, int _iMoney)
	:CObj(_strName, _iPower, _iHP, _iMoney)
{
}

CMonster::~CMonster()
{
}
