// 좌표정렬.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>

#define dimension 2

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> coordinateX;
	vector<int> coordinateY;
	
	int x, y;
	for (int i = 0; i < N; i++)
	{
		x = y = 0;
		cin >> x >> y;
		coordinateX.push_back(x);
		coordinateY.push_back(y);
	}

	for (int i = 0; i < coordinateX.size(); i++)
	{
		for (int j = i; j < coordinateX.size(); j++)
		{
			if (coordinateX[i] > coordinateX[j])
			{
				int temp;
				temp = coordinateX[i];
				coordinateX[i] = coordinateX[j];
				coordinateX[j] = temp;
			}
		}
	}

	for (int i = 0; i < coordinateY.size(); i++)
	{
		for (int j = i; j < coordinateY.size(); j++)
		{
			if (coordinateY[i] > coordinateY[j])
			{
				int temp;
				temp = coordinateY[i];
				coordinateY[i] = coordinateY[j];
				coordinateY[j] = temp;
			}
		}
	}

	int tempX(0), tempY(0);
	for (int i = coordinateX.size() - 1; i >= 0; i--)
	{
		if (tempX == coordinateX[i] && tempY == coordinateY[i])
		{
			coordinateX.erase(coordinateX.begin() + i);
			coordinateY.erase(coordinateY.begin() + i);
		}
		else
		{
			tempX = coordinateX[i];
			tempY = coordinateY[i];
		}
	}


	for (int i = 0; i < coordinateX.size(); i++)
	{
		cout << coordinateX[i] << " ";
		cout << coordinateY[i] << endl;
	}
}
