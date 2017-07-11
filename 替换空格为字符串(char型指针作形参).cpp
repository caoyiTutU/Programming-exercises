// C++study.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length);
};

void Solution::replaceSpace(char *str, int length)
{
	int l = length;
	for (int i = 0;i < l;++i)
	{
		if (isspace(str[i]))
			length += 2;
	}
	str[length] = '\0';
	for (int j =l-1;j >=0;--j)
	{
		if (!isspace(str[j]))
		{
			str[--length] = str[j];
		}
		else
		{
			str[--length] = '0';
			str[--length] = '2';
			str[--length] = '%';
		}
	}
}

int main()
{
	char str[20] = "hello world";
	Solution sol;
	sol.replaceSpace(str, 11);
	cout << str << endl;
	system("pause");
	return 0;
}

