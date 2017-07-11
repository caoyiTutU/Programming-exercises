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

class Solution {
public:
	vector<int> multiply(const vector<int>& A);
};

vector<int> Solution::multiply(const vector<int>& A)
{
	vector<int> B;
	int factor = 1;
	int flag = 0;
	for (const auto &i : A)
	{
		if (i == 0)
			++flag;
		factor *= i;
	}
	if (flag > 1)
	{
		vector<int> C(A.size(), 0);
		return C;
	}
	else if(flag==1)
	{
		int index;
		int factor_0 = 1;
		for (unsigned k = 0;k < A.size();++k)
		{
			if (A[k] == 0)
				index = k;
			else
			{
				factor_0 *= A[k];
				B.push_back(0);
			}
		}
		auto iter = B.begin() + index;
		B.insert(iter, factor_0);
	}
	else
	{
		for (unsigned j = 0;j < A.size();++j)
		{
			int temp = round(exp(log(abs(factor)) - log(abs(A[j]))));
			if (factor*A[j] > 0)
				B.push_back(temp);
			else
				B.push_back(-temp);
		}
	}
	return B;
}

int main()
{
	Solution sol;
	vector<int> A = { 1,4,-2,3,5 };
	vector<int> B = sol.multiply(A);
	for (const auto &b : B)
		cout << b << endl;
	system("pause");
	return 0;
}