#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<set>
#include<map>
#include<iterator>
#include<sstream>

using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m);
};

int Solution::LastRemaining_Solution(int n, int m)
{
	if (m < 1)
		return -1;
	vector<int> ivec;
	for (int i = 0;i < n;++i)
		ivec.push_back(i);
	int index = 0;
	unsigned len = 0;
	while ((len = ivec.size()) > 1)
	{
		index = m - 1;
		if (len < m)
			while (index > len - 1)
				index = index - len;
		auto iter = ivec.begin() + index;
		iter = ivec.erase(iter);
		rotate(ivec.begin(), iter, ivec.end());
	}
	return ivec.at(0);
}

int main()
{
	Solution sol;
	cout << sol.LastRemaining_Solution(5, 7) << endl;
	system("pause");
	return 0;
}