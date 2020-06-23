// 1712_손익분기점.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct Laptop
{
	long fixed_expense;
	long variable_expense;
	long selling_price;
};
int main()
{
	Laptop laptop;
	cin >> laptop.fixed_expense;
	cin >> laptop.variable_expense;
	cin >> laptop.selling_price;

	if (laptop.variable_expense >= laptop.selling_price)
	{
		cout << -1 << endl;
	}
	else
	{
		long result = laptop.fixed_expense / (laptop.selling_price - laptop.variable_expense) + 1;
		cout << result << endl;
		
	}
	return 0;
}
