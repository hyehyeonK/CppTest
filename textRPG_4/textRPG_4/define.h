#pragma once

#define		SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

typedef struct tagInfo
{
	char	szName[128];
	int		iHP;
	int		iPower;

	tagInfo() {};
	tagInfo(char* _szName, int _iHP, int _iPower)
		:iHP(_iHP), iPower(_iPower)
	{
		strcpy_s(szName, _szName);
	}
}INFO;
