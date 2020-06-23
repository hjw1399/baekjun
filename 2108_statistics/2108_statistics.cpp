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
		sum += (double)data[i];
	}
	return (int)floor(sum / N + 0.5);
}

int Median_index(const int& N)
{
	return ((1 + N) / 2) - 1;
}

int mode_index(int *data)
{
	#ifdef _WIN32
		unsigned int length = _msize(data) / sizeof(int); // data 길이 획득
	#elif linux
		unsigned int length = malloc_usable_size(data) / sizeof(int);
	#endif
	// initial count is 1. because we have at least a datum.

	/*  
		입력 받은 data는 sort함수로 이미 정렬이 된 data입니다.

		처음에 count를 1로 초기화 한다음,
		현재 값과 다음 인덱스의 값이 일치한다면 count++으로 개수를 셀 생각입니다. 일치하지 않는다면, 우선 count = 1로 다시 초기화 할 것입니다.
		그리고 카운트가 기억된 max_count 보다 크다면, 그 당시의 i값을 저장하여 최빈값의 인덱스를 기억합니다.
		그리고 max_count를 재정의 합니다. 
		첫 번째로 작은 최빈값을 찾았으므로 2st로 작은 최빈값은 아직 찾지 못하였으므로 isFound2nd = false입니다.

		그리고 두번째 최빈값을 찾지 못했을 때, count와 기억한 max_count가 동일한 경우 다음 i+1 mode_index에 저장합니다.
		그리고 2번째로 작은 최빈값을 찾았으니 다시는 이러한 일을 반복하지 않습니다. (더 큰 빈도를 갖는 최빈값이 나오기 전까지)

		이것을 반복하면 가장 많은 count가 된 값의 index가 반환될 것이고,
		동일한 빈도를 가진 최빈값은 두번째로 작은 값의 index가 반환될 것입니다.
	*/
	unsigned int remember_max_count = 1; 
	unsigned int mode_index = 0; 
	unsigned int count = 1;
	bool isFound2nd = false;
	for (size_t i = 0; i < length - 1; i++) // We must set for-loop's length one less than the length. because of Segmentation fault
	{
		if (data[i] == data[i + 1])
		{
			count++;
		}
		else
		{
			count = 1;
		}

		if (count > remember_max_count)
		{
			mode_index = i;
			remember_max_count = count;
			isFound2nd = false;
		}
		else if (count == remember_max_count && !isFound2nd)
		{ 
			mode_index = i + 1;
			isFound2nd = true;
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

	cout << Average(data) << endl;
	cout << data[Median_index(N)] << endl;
	cout << data[mode_index(data)] << endl;
	cout << Ragne(data) << endl;


	delete[] data;

	return 0;
}
