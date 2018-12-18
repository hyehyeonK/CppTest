// Main.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "GradeTable.h"
/*
* 성적표 프로그램 
1 추가
2 삭제
3 탐색
4 출력
5 수정
6 정렬 -> 버블정렬
7 종료
*/
int main()
{

	CGradeTable* GradeTable = new CGradeTable();
	GradeTable->Init();
	GradeTable->Progress();
	SAFE_DELETE(GradeTable);

    return 0;
}
