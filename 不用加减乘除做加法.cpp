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
	int Add(int num1, int num2);
};

int Solution::Add(int num1, int num2)
{
	int result = 0;
	int factor = 0;
	int k = 0;
	int pos = 0;
	while (num1 != 0 || num2 != 0 || factor == 1)
	{
		int temp = num1^num2^factor;
		temp &= 1;
		if (temp == 0)
		{
			if (num1 & 1 || num2 & 1)
				factor = 1;
			else
				factor = 0;
		}
		else
		{
			if (num1 & 1 && num2 & 1 && factor)
				factor = 1;
			else
				factor = 0;
		}
		result |= (temp << k++);
		num1 >>= 1;
		num2 >>= 1;
		if (++pos == 32)
			break;
	}
	return result;
}

int main()
{
	Solution sol;
	cout << sol.Add(1, -23) << endl;
	system("pause");
	return 0;
}