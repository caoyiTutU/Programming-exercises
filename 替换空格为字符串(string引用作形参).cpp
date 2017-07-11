// C++study.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	void replaceSpace(string &str, int length);
};

void Solution::replaceSpace(string &str, int length)
{
	string s1(str);
	str = "";
	for (unsigned i = 0;i < s1.size();++i)
	{
		if (!isspace(s1[i]))
			str += s1[i];
		else
			str += "%20";
	}
}

int main()
{
	string str = "hello world and ni hao";
	Solution sol;
	sol.replaceSpace(str, 10);
	cout << str << endl;
	system("pause");
	return 0;
}
