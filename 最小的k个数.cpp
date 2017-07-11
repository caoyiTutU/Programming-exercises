#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>

using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k);
};

vector<int> Solution::GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> ivec;
	sort(input.begin(), input.end());
	if (input.empty() || k > input.size())
		return ivec;
	for (int i = 0;i < k;++i)
		ivec.push_back(input.at(i));
	return ivec;
}

int main()
{
	Solution sol;
	vector<int> input = { 4,5,1,6,2,7,3,8 }, result;
	result = sol.GetLeastNumbers_Solution(input, 9);
	for (const auto &i : result)
		cout << i << endl;
	system("pause");
	return 0;
}