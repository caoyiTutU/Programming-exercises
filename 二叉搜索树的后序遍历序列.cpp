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
#include<stack>

using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence);
	bool checkeach(vector<int> ivec);
};

bool Solution::VerifySquenceOfBST(vector<int> sequence)
{
	if (sequence.empty())
		return false;
	return checkeach(sequence);
}

bool Solution::checkeach(vector<int> ivec)
{
	if (ivec.empty() || ivec.size() == 1)
		return true;
	int end = ivec.back();
	auto iter = find_if(ivec.begin(), ivec.end(), [end](int i) {return i > end;});
	if (iter == ivec.end())
		return checkeach(vector<int>(ivec.begin(), ivec.end() - 1));
	else
	{
		auto iter1 = iter;
		while (iter1 != ivec.end() - 1)
		{
			if (*iter1 < end)
				return false;
			++iter1;
		}
		return checkeach(vector<int>(ivec.begin(), iter)) && checkeach(vector<int>(iter, ivec.end() - 1));
	}
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
