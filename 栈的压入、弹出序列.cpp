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
	bool IsPopOrder(vector<int> pushV, vector<int> popV);
};

bool Solution::IsPopOrder(vector<int> pushV, vector<int> popV)
{
	if (pushV.empty())
		return false;
	auto iter1 = pushV.begin();
	auto iter2 = popV.begin();
	stack<int> temp;
	while (iter1 != pushV.end())
	{
		temp.push(*iter1++);
		while (!temp.empty() && iter2 != popV.end() && temp.top() == *iter2)
		{
			temp.pop();
			++iter2;
		}
	}
	if (temp.empty())
		return true;
	else
		return false;
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}