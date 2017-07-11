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
	void push(int value);
	void pop();
	int top();
	int min();
private:
	vector<int> ivec;
};

void Solution::push(int value)
{
	ivec.push_back(value);
}

void Solution::pop()
{
	if (!ivec.empty())
		ivec.erase(ivec.end() - 1);
}

int Solution::top()
{
	if (!ivec.empty())
		return ivec.back();
	else
		return 0;
}

int Solution::min()
{
	if (ivec.empty())
		return 0;
	int min = ivec.front();
	for (auto iter = ivec.begin() + 1;iter != ivec.end();++iter)
		if (*iter < min)
			min = *iter;
	return min;
}

int main()
{
	Solution sol;
	int val;
	while (cin >> val)
		sol.push(val);
	for (int i = 0;i < 2;++i)
		sol.pop();
	cout << sol.top() << " " << sol.min() << endl;
	system("pause");
	return 0;
}