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
	int Sum_Solution(int n);
private:
	int sum = 0;
};

int Solution::Sum_Solution(int n)
{

	(n < 0) || (n && (sum = n + Sum_Solution(n - 1)));
	return sum;
}

int main()
{
	Solution sol;
	cout << sol.Sum_Solution(5) << endl;
	system("pause");
	return 0;
}