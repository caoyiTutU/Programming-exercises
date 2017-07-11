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

using namespace std;

class Solution {
public:
	bool match(char* str, char* pattern);
	bool matchone(char *s, char* p);
};

bool Solution::match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;
	return matchone(str, pattern);
}

bool Solution::matchone(char* s, char* p)
{
	if (*s == '\0'&&*p == '\0')
		return true;
	if (*s != '\0'&&*p == '\0')
		return false;
	if (*(p + 1) == '*')
	{
		if (*s == *p || (*p == '.'&&*s != '\0'))
			return matchone(s, p + 2) || matchone(s + 1, p);
		else
			return matchone(s, p + 2);
	}
	else
	{
		if (*s == *p || (*p == '.'&&*s != '\0'))
			return matchone(s + 1, p + 1);
		else
			return false;
	}
}

int main()
{
	Solution sol;
	char str[] = "aaa", pattern[] = "ab*a";
	cout << sol.match(str, pattern) << endl;
	system("pause");
	return 0;
}