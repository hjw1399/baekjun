// 2839_delivery_sugar.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

struct Plastic_bag
{
	int kg_5;
	int kg_3;
};
int Optimized_sugar_plastic_bag_number(const int& mass)
{
	int temp_mass = mass;
	while (temp_mass > 0)
	{
		if (temp_mass % 5 == 0)
		{
			Plastic_bag plastic_bag;
			plastic_bag.kg_5 = temp_mass / 5;
			plastic_bag.kg_3 = (mass - temp_mass) / 3;
			return plastic_bag.kg_5 + plastic_bag.kg_3;
		}
		else
		{
			temp_mass -= 3;
		}
	}
	if (mass % 3 == 0)
	{
		return mass / 3;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int sugar_mass;
	cin >> sugar_mass;
	cout << Optimized_sugar_plastic_bag_number(sugar_mass) << endl;
	return 0;
}

