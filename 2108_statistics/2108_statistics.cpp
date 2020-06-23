// 2108_statistics.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include "stdio.h"
#include <malloc.h>

using namespace std;

int Average(int *data)
{
	double sum = 0;
	#ifdef _WIN32
		unsigned int length = _msize(data) / sizeof(int);
	#elif linux
		unsigned int length = malloc_usable_size(data) / sizeof(int);
	#endif
	double N = (double)length;
	for (size_t i = 0; i < length; i++)
	{
		sum += data[i];
	}
	return floor(sum / N + 0.5);
}

int Median_index(const int& N)
{
	return ((1 + N) / 2) - 1;
}

int mode_index(int *data)
{
	#ifdef _WIN32
		unsigned int length = _msize(data) / sizeof(int);
	#elif linux
		unsigned int length = malloc_usable_size(data) / sizeof(int);
	#endif
	// initial count is 1. because we have at least a datum.
	unsigned int remember_max_count = 1; 
	unsigned int mode_index = 0; 
	unsigned int count = 1;
	std::vector<unsigned int> same_frequency_indices;
	bool isFound2st = false;
	for (size_t i = 0; i < length; i++)
	{
		if (data[i] == data[i + 1])
		{
			count++;
			if (!isFound2st)
			{
				remember_max_count = count; // At first, remember_max_count has to go up together.
			}
		}
		else
		{
			if (count > remember_max_count)
			{
				mode_index = i;
				remember_max_count = count;
			}
			else if (count == remember_max_count && !isFound2st)
			{ 
				mode_index = i + 1;
				isFound2st = true;
			}
			count = 1;
		}
	}

	return mode_index;
}

int Ragne(int *data)
{
	#ifdef _WIN32
		unsigned int length = _msize(data) / sizeof(int);
	#elif linux
		unsigned int length = malloc_usable_size(data) / sizeof(int);
	#endif
	return data[length - 1] - data[0];
}

int main()
{
	int N;
	cin >> N;
	int *data = new int[N];
	for (auto i = 0; i < N; i++)
	{
		cin >> data[i];
	}
	sort(data, data + N);
	/*for (auto i = 0; i < N; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;*/
	cout << Average(data) << endl;
	cout << data[Median_index(N)] << endl;
	cout << data[mode_index(data)] << endl;
	cout << Ragne(data) << endl;
	

	delete[] data;
}