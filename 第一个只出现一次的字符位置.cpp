#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<set>

using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str);
};

int Solution::FirstNotRepeatingChar(string str)
{
	if (str.size()==1)
		return 0;
	vector<pair<char, int>> pvec;
	for (const auto &c : str)
	{
		int flag = 0;
		for (auto &p : pvec)
		{
			if (p.first == c)
			{
				++p.second;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			pvec.push_back(make_pair(c, 1));
	}
	auto iter = find_if(pvec.begin(), pvec.end(), [](const pair<char, int>& pa) {return pa.second == 1; });
	if (iter == pvec.end())
		return -1;
	auto position = str.find(iter->first);
	return position;
}

int main()
{
	Solution sol;
	string str = "BECJSBJESEAIODGOIEGCA";
	cout << sol.FirstNotRepeatingChar(str) << endl;
	system("pause");
	return 0;
}