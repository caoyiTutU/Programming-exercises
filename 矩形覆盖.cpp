#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
	int rectCover(int number);
private:
	vector<int> ivec = { 1,2 };
};

int Solution::rectCover(int number)
{
	if (number == 0)
	{
		return 0;
	}
	else if (number == 1)
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
		rectCover(--number);
	}
	return ivec.back();
}

int main()
{
	Solution sol;
	cout << sol.rectCover(7) <<endl;
	system("pause");
	return 0;
}