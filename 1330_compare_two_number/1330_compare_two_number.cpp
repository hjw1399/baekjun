// 1330_compare_two_number.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A;
	cin >> B;
	if (A > B)	cout << ">" << endl;
	else if (A < B) cout << "<" << endl;
	else cout << "==" << endl;
}

