#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
	int jumpFloorII(int number);
private:
	vector<int> ivec = { 1,1 };
};

int Solution::jumpFloorII(int number)
{
	if (number == 0 || number == 1)
	{
		return 1;
	}
	else
	{
		ivec.push_back(accumulate(ivec.begin(), ivec.end(), 0));
		jumpFloorII(--number);
	}
	return ivec.back();
}

int main()
{
	Solution sol;
	cout << sol.jumpFloorII(4) <<endl;
	system("pause");
	return 0;
}