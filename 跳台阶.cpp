#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
	int jumpFloor(int number);
private:
	vector<int> ivec = { 1,2 };
};

int Solution::jumpFloor(int number)
{
	if (number == 1)
	{
		return 1;
	}
	else if (number == 2)
	{
		return 2;
	}
	else
	{
		ivec.push_back(accumulate(ivec.end() - 2, ivec.end(), 0));
		jumpFloor(--number);
	}
	return ivec.back();
}

int main()
{
	Solution sol;
	cout << sol.jumpFloor(2) <<endl;
	system("pause");
	return 0;
}