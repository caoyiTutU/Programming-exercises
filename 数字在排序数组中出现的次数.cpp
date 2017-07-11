#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<set>

using namespace std;

//二分搜索算法

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k);
};

int Solution::GetNumberOfK(vector<int> data, int k)
{
	auto pair = equal_range(data.begin(), data.end(), k);
	return pair.second - pair.first;
}

int main()
{
	Solution sol;
	vector<int> ivec = { 2,3,3,5,5,5,5,6,7,8,8 };
	cout << sol.GetNumberOfK(ivec, 5) << endl;
	system("pause");
	return 0;
}