// Main.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "GradeTable.h"
/*
* ����ǥ ���α׷� 
1 �߰�
2 ����
3 Ž��
4 ���
5 ����
6 ���� -> ��������
7 ����
*/
int main()
{

	CGradeTable* GradeTable = new CGradeTable();
	GradeTable->Init();
	GradeTable->Progress();
	SAFE_DELETE(GradeTable);

    return 0;
}
