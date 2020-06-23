// 2751_sort_nlogn.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long N;
	cin >> N;
	long *data = new long[N];
	for (size_t i = 0; i < N; i++)
	{
		cin >> data[i];
	}
	std::stable_sort(data, data + N);
	for (size_t i = 0; i < N; i++)
	{
		cout << data[i] << endl;
	}
}

