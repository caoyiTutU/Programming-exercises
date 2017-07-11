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
#include<math.h>

using namespace std;

class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch);
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce();
	string str;
};

void Solution::Insert(char ch)
{
	str += ch;
}

char Solution::FirstAppearingOnce()
{
	if (str.empty())
		return '#';
	int flag = 0;
	vector<pair<char, int>> pvec;
	for (const auto &c : str)
	{
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
		else
			flag = 0;
	}
	auto iter = find_if(pvec.begin(), pvec.end(), [](const pair<char, int> pa) {return pa.second == 1;});
	if (iter != pvec.end())
		return iter->first;
	else
		return '#';
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}