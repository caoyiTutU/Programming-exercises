#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>

using namespace std;

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n);
};

int Solution::NumberOf1Between1AndN_Solution(int n)
{
	int cnt = 0, k;
	for (int i = 1;k = n / i;i *= 10)
	{
		cnt += k / 10 * i;
		int m = k % 10;
		if (m > 1)
			cnt += i;
		else if (m == 1)
			cnt += n - i*k + 1;
	}
	return cnt;
}

int main()
{
	Solution sol;
	cout << sol.NumberOf1Between1AndN_Solution(10) << endl;
	system("pause");
	return 0;
}