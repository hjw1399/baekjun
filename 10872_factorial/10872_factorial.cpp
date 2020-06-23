// 2839_delivery_sugar.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

int Facotorial(const int& N)
{
	if (N == 1 || N == 0)
	{
		return 1;
	}
	return N * Facotorial(N - 1);
}

int main()
{
	int N;
	cin >> N;
	cout << Facotorial(N) << endl;
	return 0;
}

