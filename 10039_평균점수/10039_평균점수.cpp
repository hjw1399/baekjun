// 10039_평균점수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int Mean(const vector<int>& temp)
{
	int sum(0);
	for (size_t i = 0; i < temp.size(); i++)
	{
		sum += temp.at(i);
	}
	return sum / temp.size();
}

int main()
{
	int data = 0;
	std::vector<int> dataes;
	for (size_t i = 0; i < 5; i++)
	{
		cin >> data;
		if (data < 40)
		{
			data = 40;
		}
		dataes.push_back(data);
	}
	cout << Mean(dataes) << endl;
}
    
