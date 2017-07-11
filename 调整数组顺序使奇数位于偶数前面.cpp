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
	void reOrderArray(vector<int> &array);
};


void Solution::reOrderArray(vector<int> &array)
{
	vector<int> ivec1, ivec2;
	partition_copy(array.begin(), array.end(), back_inserter(ivec1), back_inserter(ivec2), [](int i) {return i % 2 == 1;});
	auto iter = copy(ivec1.begin(), ivec1.end(), array.begin());
	copy(ivec2.begin(), ivec2.end(), iter);
}

int main()
{
	Solution sol;
	vector<int> ivec = { 3,2,1,6,9,7,6,8,9,2,4,6,7 };
	sol.reOrderArray(ivec);
	for (auto &i : ivec)
	{
		cout << i << endl;
	}
	system("pause");
	return 0;
}


