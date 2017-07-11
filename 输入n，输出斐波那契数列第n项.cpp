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

using namespace std;


class Solution {
public:
	int Fibonacci(int n);
private:
	vector<int> ivec = { 1,1 };
};

int Solution::Fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		ivec.push_back(accumulate(ivec.end() - 2, ivec.end(), 0));
		Fibonacci(--n);
	}
	return ivec.back();
}


int main()
{
	Solution sol;
	cout << sol.Fibonacci(7) << endl;
	system("pause");
	return 0;
}


