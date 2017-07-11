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

using namespace std;
using namespace placeholders;


class Solution {
public:
	int  NumberOf1(int n);
};

int Solution::NumberOf1(int n)
{
	int cnt = 0;
	while (n != 0)
	{
		n = n&(n - 1);
		++cnt;
	}
	return cnt;
}


int main()
{
	Solution sol;
	cout << sol.NumberOf1(-2) << endl;
	system("pause");
	return 0;
}


