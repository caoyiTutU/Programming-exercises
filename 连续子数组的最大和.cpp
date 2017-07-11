#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array);
};

int Solution::FindGreatestSumOfSubArray(vector<int> array)
{
	int sum = 0, max = 0;
	for (const auto &i : array)
	{
		sum += i;
		if (sum < 0)
			sum = 0;
		else
			if (sum > max)
				max = sum;
	}
	if (max != 0)
		return max;
	else
	{
		sort(array.begin(), array.end());
		return array.back();
	}
}

int main()
{
	Solution sol;
	vector<int> array = { -2,-8,-1,-5,-9 };
	cout << sol.FindGreatestSumOfSubArray(array) << endl;
	system("pause");
	return 0;
}