#pragma once

enum Subject
{
	Kor,
	Eng,
	Math,
	SbjCount
};

enum Menu
{
	BACK,
	MENU_Add,
	MENU_Delete,
	MENU_Search,
	MENU_Print,
	MENU_Modi,
	MENU_Sort,
	MENU_Exit
};

enum Add
{
	Add_Name,
	Add_Kor,
	Add_Eng,
	Add_Math
};
enum Modi
{
	Modi_Name,
	Modi_Kor,
	Modi_Eng,
	Modi_Math
};

enum Sort
{
	Sort_Name = 1,
	Sort_Avg
};

#define REJECT_INPUT cout << "�߸� �� �Է��Դϴ�. �ٽ� �Է� �� �ּ���." << endl; system("pause");