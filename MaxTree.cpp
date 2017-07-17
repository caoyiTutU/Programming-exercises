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
#include<fstream>
#include<math.h>
#include<stack>
#include<iomanip>
#include<random>
#include<bitset>
#include<regex>
#include<unordered_set>
#include<unordered_map>
#include<memory>

using namespace std;

class MaxTree {
public:
	vector<int> buildMaxTree(vector<int> A, int n);
};

vector<int> MaxTree::buildMaxTree(vector<int> A, int n)
{
	vector<pair<int, int>> pvec(n);
	vector<int> res;
	stack<int> lsta, rsta;
	for (int i = 0;i < n;++i)
	{
		while (!lsta.empty() && A[lsta.top()] <= A[i])
			lsta.pop();
		if (lsta.empty())
			pvec[i].first = -1;
		else
			pvec[i].first = lsta.top();
		lsta.push(i);
	}
	
	for (int j = n-1;j >= 0;--j)
	{
		while (!rsta.empty() && A[rsta.top()] <= A[j])
			rsta.pop();
		if (rsta.empty())
			pvec[j].second = -1;
		else
			pvec[j].second = rsta.top();
		rsta.push(j);
	}
	for (const auto &pa : pvec)
	{
		if (pa.first == -1 && pa.second == -1)
			res.push_back(-1);
		else if (pa.first == -1)
			res.push_back(pa.second);
		else if (pa.second == -1)
			res.push_back(pa.first);
		else
		{
			int index = A[pa.first] > A[pa.second] ? pa.second : pa.first;
			res.push_back(index);
		}
	}
	return res;
}

int main()
{
	MaxTree mt;
	vector<int> ivec = { 3,1,4,2 }, res = mt.buildMaxTree(ivec, 4);
	for (const auto &i : res)
		cout << i << endl;
	system("pause");
	return 0;
}
