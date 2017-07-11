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
	int movingCount(int threshold, int rows, int cols);
private:
	int special(int threshold, int rc);
	int transform(int r, int c);
};

int Solution::movingCount(int threshold, int rows, int cols)
{
	if (rows < 1 || cols < 1)
		return 0;
	if (rows == 1)
		return special(threshold, cols);
	if (cols == 1)
		return special(threshold, rows);
	vector<vector<int>> vvec;
	int num_0 = 0;
	for (int i = 0;i < rows;++i)
	{
		vector<int> ivec;
		for (int j = 0;j < cols;++j)
		{
			if (transform(i, j) > threshold)
			{
				ivec.push_back(0);
				++num_0;
			}
			else
				ivec.push_back(1);
		}
		vvec.push_back(ivec);
	}
	int count = rows*cols - num_0;
	for (int i = 0;i < rows;i += 10)
		for (int j = 0;j < cols;j += 10)
			if (vvec[i][j] == 1 && threshold==transform(i,j))
				--count;
	return count;
}

int Solution::special(int thr, int rc)
{
	for (int i = 0;i < rc;++i)
	{
		if (transform(0, i) > thr)
			return i;
	}
	return rc;
}

int Solution::transform(int r, int c)
{
	int val = 0;
	string str;
	str += to_string(r) + to_string(c);
	for (const auto &c : str)
		val += c - '0';
	return val;
}



int main()
{
	Solution sol;
	cout << sol.movingCount(18, 40, 40) << endl;
	system("pause");
	return 0;
}
