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
	string ReverseSentence(string str);
};

string Solution::ReverseSentence(string str)
{
	if (str.empty())
		return str;
	istringstream is(str);
	string s;
	vector<string> svec;
	while (is >> s)
		svec.push_back(s);
	if (svec.empty())
		return str;
	s.clear();
	auto iter_r = svec.rbegin();
	while (iter_r != svec.rend()-1)
		s += *iter_r++ + " ";
	s += *iter_r;
	return s;
}

int main()
{
	Solution sol;
	string str = "   ";
	cout << sol.ReverseSentence(str) << endl;
	system("pause");
	return 0;
}