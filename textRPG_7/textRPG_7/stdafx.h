// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

#include <iostream>
#include <string>

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
#define REJECT_INPUT	cout << "\n*** �߸� �� �Է��Դϴ�. ***\n" << endl; system("pause");
using namespace std;