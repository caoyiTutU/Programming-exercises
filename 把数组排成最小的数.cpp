#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>

using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> numbers);
};

string Solution::PrintMinNumber(vector<int> numbers)
{
	string str, str1;
	vector<string> stvec;
	for (auto &i : numbers)
		stvec.push_back(to_string(i));
	unsigned len = stvec.size();
	if (len == 0)
		return str;
	else if (len == 1)
		return stvec.at(0);
	sort(stvec.begin(), stvec.end());

	while (!stvec.empty())
	{
		vector<string> svec;
		auto iter2 = stvec.begin();
		auto c1 = iter2->at(0);
		while (iter2->at(0) == c1)
		{
			svec.push_back(*iter2);
			iter2 = stvec.erase(iter2);
			if (iter2 == stvec.end())
				break;
		}
		if (svec.size() == 1)
		{
			str += svec.at(0);
			continue;
		}
		//pvec存放重复值
		vector<string> pvec;
		auto iter1 = svec.begin();
		string spre = *iter1++;
		while (iter1 != svec.end())
		{
			if (*iter1 == spre)
			{
				pvec.push_back(spre);
				iter1 = svec.erase(iter1);
				continue;
			}
			spre = *iter1++;
		}
		unsigned l = pvec.size();
		//svec为不重复值集合
		vector<string> s1 = svec;
		vector<string> strvec;
		do {
			for (auto &s : svec)
			{
				if (l != 0)
				{
					for (unsigned i = 0;i <= count(pvec.begin(), pvec.end(), s);++i)
						str1 += s;
				}
				else
				    str1 += s;
			}
			strvec.push_back(str1);
			str1.clear();
			next_permutation(svec.begin(), svec.end());
		} while (svec != s1);
		sort(strvec.begin(), strvec.end());
		str += strvec.front();
	}
	return str;
}

int main()
{
	Solution sol;
	vector<int> numbers = { 3,32,12,14,31,321,34,23,23,24 };
	cout << sol.PrintMinNumber(numbers) << endl;
	system("pause");
	return 0;
}