#pragma once
#include "Obj.h"

class CMonster : public CObj
{
public:
	CMonster();
	CMonster(string _strName, int _iPower, int _iHP, int _iMoney);
	~CMonster();
};
