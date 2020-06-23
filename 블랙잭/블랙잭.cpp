#include "pch.h"
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

std::vector<vector<unsigned int> > combinationResult;

void DoCombination(int combArr[], int n, int r, int index, int target, int arr[])
{
	if (r == 0)
	{
		std::vector<unsigned int> combinationTemp;
		for (int i = 0; i < index; i++)
		{
			combinationTemp.push_back(arr[combArr[i]]);
		}
		combinationResult.push_back(combinationTemp);
	}
	else if (target == n) return;
	else
	{
		combArr[index] = target;
		DoCombination(combArr, n, r - 1, index + 1, target + 1, arr);
		DoCombination(combArr, n, r, index, target + 1, arr);
	}
}

void ThreeSummation()
{

}

int main()
{
	int N, M;
	cin >> N >> M;
	std::vector<int> cards;
	int tempValue(0);

	for (int i = 0; i < N; i++)
	{
		cin >> tempValue;
		cards.push_back(tempValue);
	}
	
	int *combArr = new int[N];
	int arr[] = { 0, 1, 2, 3, 4 };
	DoCombination(combArr, N, 3 , 0, 0, arr);

	int sum;
	int rememberSum;
	int rememberDiff(200000000);
	bool isTerminate(false);
	for (int i = 0; i < combinationResult.size(); i++)
	{
		sum = 0;
		for (int j = 0; j < combinationResult[i].size(); j++)
		{
			sum += cards[ combinationResult[i][j] ];
		}
		if (M == sum)
		{
			cout << sum;
			isTerminate = true;
			break;
		}
		else if (M - sum > 0)
		{
			if (M - sum < rememberDiff)
			{
				rememberSum = sum;
				rememberDiff = M - sum;
			}
		}
		else if (M - sum < 0)
		{
			continue;
		}
	}
	if(!isTerminate)
		cout << rememberSum << endl;

	return 0;
}
