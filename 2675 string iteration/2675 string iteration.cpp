// 2675 string iteration.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int test_case_number;
	cin >> test_case_number;
	for (auto i = 0; i < test_case_number; i++)
	{
		int iteration_number;
		string input_str;

		cin >> iteration_number;
		std::getline(cin, input_str);
		/*
			It's separated by one blank.
			so, the string's first character is blank.
			so I will use index 1 not 0.
		*/

		for (size_t i = 1; i < input_str.size(); i++)
		{
			for (size_t j = 0; j < iteration_number; j++)
			{
				cout << input_str[i];
			}
		}
		cout << endl;
	}
}
