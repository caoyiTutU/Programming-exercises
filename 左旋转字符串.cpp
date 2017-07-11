#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<set>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n);
};

string Solution::LeftRotateString(string str, int n)
{
	unsigned len = str.size();
	if (len == 0)
		return str;
	int m = n%len;
	if (m == 0)
		return str;
	auto iter = str.begin() + m;
	rotate(str.begin(), iter, str.end());
	return str;
}

int main()
{
	Solution sol;
	string str = "abcXYZdef";
	cout << sol.LeftRotateString(str, 5) << endl;
	system("pause");
	return 0;
}