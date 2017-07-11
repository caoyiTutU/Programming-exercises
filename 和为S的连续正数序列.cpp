#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<set>
#include<map>

using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum);
};

vector<vector<int>> Solution::FindContinuousSequence(int sum)
{
	vector<vector<int>> vvec;
	int i = 2;
	while (1)
	{
		if (i % 2)                   
		{
			int inter = sum / i;
			int beg = inter - (i - 1) / 2;
			if (beg <= 0)
				break;
			if (sum % i == 0)
			{
				vector<int> ivec;
				for (int j = beg;j < beg + i;++j)
					ivec.push_back(j);
				vvec.push_back(ivec);
			}
		}
		else
		{
			if (sum % (i / 2) == 0)
			{
				int inter1 = sum / (i / 2);
				if (inter1 % 2)
				{
					int beg1 = inter1 / 2 - (i / 2 - 1);
					if (beg1 > 0)
					{
						vector<int> ivec1;
						for (int k = beg1;k < beg1 + i;++k)
							ivec1.push_back(k);
						vvec.push_back(ivec1);
					}
					else
						break;
				}
			}
		}
		++i;
	}
	reverse(vvec.begin(), vvec.end());
	return vvec;
}

int main()
{
	Solution sol;
	vector<vector<int>> vvec;
	vvec = sol.FindContinuousSequence(99);
	for (const auto &a : vvec)
	{
		for (const auto &b : a)
			cout << b << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}