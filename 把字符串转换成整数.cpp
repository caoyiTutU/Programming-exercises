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
	int StrToInt(string str);
};

int Solution::StrToInt(string str)
{
	if (str.empty() || str.size() > 11)
		return 0;
	int result;
	long long temp = 0;
	long long min = -2147483647, max = 2147483647;
	int k = 0;
	int index = str.size() - 1;
	while (index > 0)
	{
		if (str[index] < 48 || str[index]>57)
			return 0;
		else
			temp += (str[index--] - 48) * pow(10, k++);
	}
	if (str[index] >= 48 && str[index] <= 57)
		temp += (str[index--] - 48) * pow(10, k);
	else if (str[index] == '+');
	else if (str[index] == '-')
		temp = -temp;
	else
		return 0;
	if (temp < min-1 || temp>max)
		return 0;
	result = temp;
	return result;
}

int main()
{
	Solution sol;
	cout << sol.StrToInt("2147483648") << endl;
	system("pause");
	return 0;
}