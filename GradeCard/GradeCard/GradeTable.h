#pragma once
#include <vector>
#include "Student.h"

class CGradeTable
{
private:
	vector<CStudent>	m_Vec;

public:
	void Init();
	void Progress();

private:
	void PrintMenu();
	void Add();
	void Delete();
	void Search();
	void Print();
	void Modify();
	void Sort();

public:
	CGradeTable();
	~CGradeTable();
};

