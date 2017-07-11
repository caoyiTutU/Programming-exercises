#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<set>

using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index);
};

int Solution::GetUglyNumber_Solution(int index)
{
	set<int> iset = { 1,2,3,4,5,6 };
	int l = 6;
	if (index <= 6)
		return index;
	while (l < index)
	{
		auto iter = --iset.end();
		set<int>::iterator iter1;
		int factor = 2;
		vector<int> ivec;
		for (int i = 0;i < 3;++i)
		{
			auto pair = iset.insert(*iter / factor);
			if (pair.second)
				 iter1 = iset.erase(pair.first);
			else
				 iter1 = ++pair.first;
			ivec.push_back(*iter1*factor);
			if (i == 0)
				factor = 3;
			else if (i == 1)
				factor = 5;
		}
		auto iter2 = min_element(ivec.begin(), ivec.end());
		iset.insert(*iter2);
		++l;
	}
	return *--iset.end();
}

int main()
{
	Solution sol;
	cout << sol.GetUglyNumber_Solution(1500) << endl;
	system("pause");
	return 0;
}