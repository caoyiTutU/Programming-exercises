#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>

using namespace std;

class Solution {
public:
	vector<string> Permutation(string str);
};

vector<string> Solution::Permutation(string str)
{
	vector<string> result;
	unsigned len = str.size();
	char c = 1;
	if (len < 1 || len >9)
		return result;
	sort(str.begin(), str.end());
	vector<pair<char, char>> pvec;
	char cpre = str.at(0);
	for (unsigned i = 1;i < len;++i)
	{
		if (str.at(i) == cpre)
		{
			pvec.push_back(make_pair(str.at(i), c));
			cpre = str.at(i);
			str.at(i) = c++;
			continue;
		}
		cpre = str.at(i);
	}
	string s = str;
	result.push_back(str);
	next_permutation(str.begin(), str.end());
	while (str != s)
	{
		result.push_back(str);
		next_permutation(str.begin(), str.end());
	}
	for (auto iter1 = result.begin();iter1 != result.end();++iter1)
		for (unsigned l = 0;l < pvec.size();++l)
			replace(iter1->begin(), iter1->end(), pvec[l].second, pvec[l].first);
	sort(result.begin(), result.end());
	auto iter2 = unique(result.begin(), result.end());
	result.erase(iter2, result.end());
	return result;
}


int main()
{
	Solution sol;
	string str = "abfsa";
	vector<string> svec;
	svec = sol.Permutation(str);
	for (const auto &s : svec)
	{
		cout << s << endl;
	}
	system("pause");
	return 0;
}