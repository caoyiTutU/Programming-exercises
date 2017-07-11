// C++study.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<iterator>
#include<cassert>
#include"person.h"
#include<fstream>
#include<sstream>
#include<array>
#include<list>
#include<deque>
#include<forward_list>
#include<algorithm>
#include<numeric>
#include<functional>
#include<map>
#include<set>
#include<memory>

using namespace std;
using namespace placeholders;

class Solution {
public:
	double Power(double base, int exponent);
};

double Solution::Power(double base, int exponent)
{
	vector<double> dvec;
	int factor;
	double result = 1;
	if (exponent == 0)
		return 1;
	factor = exponent > 0 ? exponent : (-exponent);
	for (unsigned i = 0;i < factor;++i)
	{
		dvec.push_back(base);
	}
	for (auto &d : dvec)
	{
		result *= d;
	}
	if (exponent < 0)
		return 1 / result;
	return result;
}

int main()
{
	Solution sol;
	cout << sol.Power(2.5, 2);
	system("pause");
	return 0;
}


