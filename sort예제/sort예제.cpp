// sort예제.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> hi;
	hi.push_back(5);
	hi.push_back(3);
	hi.push_back(1);
	hi.push_back(7);

	sort(hi.begin(), hi.end());

	for (int i = 0; i < hi.size(); i++)
	{
		cout << hi[i] << " ";
	}
	cout << endl;
}


