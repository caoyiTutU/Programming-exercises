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
	void FindNumsAppearOnce(vector<int> data, int *num1, int *num2);
};

void Solution::FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
{
	map<int, int> imap;
	for (const auto &d : data)
	{
		++imap[d];
		if (imap[d] == 2)
			imap.erase(d);
	}
	auto iter = imap.begin();
	auto end = imap.end();
	if (iter != end)
		*num1 = iter++->first;
	if (iter != end)
		*num2 = iter->first;
}

int main()
{
	Solution sol;
	vector<int> ivec = { 1,3,5,1,7,7,4,3,6,6 };
	int num1 = 0, num2 = 0;;
	sol.FindNumsAppearOnce(ivec, &num1, &num2);
	cout << num1 << "  " << num2 << endl;
	system("pause");
	return 0;
}