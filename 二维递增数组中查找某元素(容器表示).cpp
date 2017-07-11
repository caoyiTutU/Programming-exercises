// C++study.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<cstdlib>
using namespace std;

class Solution 
{
public:
	bool Find(vector<vector<int> > array, int target);
};

bool Solution::Find(vector<vector<int> > array, int target)
{
	for (auto line : array)
	{
		for (auto list : line)
		{
			if (list > target)
			{
				break;
			}
			else if(list == target)
			{
				return true;
			}
		}
	}
	return false;
}



int main()
{
	int temp;
	int flag = 0;
	unsigned i = 0, length = 0;
	char c;
	vector<int> ivec;
	vector<vector<int>> iarray;
	while (cin >> temp)
	{
		if (flag == 0)
		{
			ivec.push_back(temp);
		}
		else
		{
			ivec[i++] = temp;
			if (i == length)
			{
				i = 0;
			}
		}

		if ((c = getchar()) == '\n')
		{
			iarray.push_back(ivec);
			if (flag == 0)
			{
				length = ivec.size();
				flag = 1;
			}
		}
	}
	
	Solution sol;
	bool result;
	result = sol.Find(iarray, 1);
	cout << result << endl;
	system("pause");
	return 0;
}
