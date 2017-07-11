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

class Solution
{
public:
	void push(int node);
	int pop();
private:
	stack<int> stack1;
	stack<int> stack2;
};

void Solution::push(int node)
{
	stack1.push(node);
}

int Solution::pop()
{
	if (stack1.empty())
		return 0;
	int l = stack1.size() - 1;
	for (int i = 0;i < l;++i)
	{
		stack2.push(stack1.top());
		stack1.pop();
	}
	int result = stack1.top();
	stack1.pop();
	for (int j = 0;j < l;++j)
	{
		stack1.push(stack2.top());
		stack2.pop();
	}
	return result;
}

int main()
{
	Solution sol;
	for (int i = 1;i < 4;++i)
		sol.push(i);
	for (int j = 0;j < 2;++j)
		cout << sol.pop() << endl;
	system("pause");
	return 0;
}