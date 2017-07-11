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
#include<math.h>
#include<stack>

using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size);
};

vector<int> Solution::maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> ivec;
	if (size == 0 || num.empty() || size > num.size())
		return ivec;
	else if (size == 1)
		return num;
	auto iter1 = num.begin(), iter2 = iter1 + size;
	while (iter2 != num.end())
	{
		ivec.push_back(*max_element(iter1, iter2));
		++iter1;
		++iter2;
	}
	ivec.push_back(*max_element(iter1, iter2));
	return ivec;
}

int main()
{
	Solution sol;
	vector<int> v = { 2,3,4,2,6,2,5,1 };
	vector<int> result = sol.maxInWindows(v, 3);
	for (const auto &i : result)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}