#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers);
};

int Solution::MoreThanHalfNum_Solution(vector<int> numbers)
{
	auto length = numbers.size() / 2;
	int cnt = 1;
	vector<int> ivec, cntvec;
	for (auto c:numbers)
	{
		for (unsigned i = 0;i < ivec.size();++i)
		{
			if (ivec[i] == c)
			{
				++cntvec[i];
				continue;
			}
		}
		ivec.push_back(c);
		cntvec.push_back(cnt);
	}
	int max = 0;
	unsigned wz;
	for (unsigned j = 0;j < cntvec.size();++j)
	{
		if (cntvec[j] > max)
		{
			max = cntvec[j];
			wz = j;
		}
	}
	if (cntvec[wz] > length)
	{
		return ivec[wz];
	}
	else
	{
		return 0;
	}
}


int main()
{
	Solution sol;
	vector<int> vec{ 1,3,3,5,3 };
	cout << sol.MoreThanHalfNum_Solution(vec) << endl;
	system("pause");
	return 0;
}