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
#include<fstream>
#include<math.h>
#include<stack>
#include<iomanip>
#include<random>
#include<bitset>
#include<regex>
#include<unordered_set>
#include<unordered_map>
#include<memory>

using namespace std;

class Solution {
public:
	void push(int value);
	void pop();
	int top();
	int min();
private:
	stack<int> datasta, minsta;
};

void Solution::push(int value)
{
	datasta.push(value);
	if (minsta.empty() || minsta.top() > value)
		minsta.push(value);
	else
		minsta.push(minsta.top());
}

void Solution::pop()
{
	datasta.pop();
	minsta.pop();
}

int Solution::top()
{
	return datasta.top();
}

int Solution::min()
{
	return minsta.top();
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
