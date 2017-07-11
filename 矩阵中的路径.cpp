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
	bool hasPath(char* matrix, int rows, int cols, char* str);
	bool search(vector<vector<char>> &v, vector<pair<int, int>> alreay, pair<int, int> cur,char *s);
};

bool Solution::hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == NULL || str == NULL || *matrix == '\0' || *str == '\0')
		return false;
	vector<vector<char>> vvec;
	vector<pair<int, int>> pvec, head;
	for (int i = 0;i < rows;++i)
	{
		vector<char> cvec;
		for (int j = 0;j < cols;++j)
		{
			if (*matrix != '\0')
			{
				if (*matrix == *str)
					head.push_back(make_pair(i, j));
				cvec.push_back(*matrix++);
			}
		}
		vvec.push_back(cvec);
	}
	for (const auto &p : head)
		if (search(vvec, pvec, p, str))
			return true;
	return false;
}

bool Solution::search(vector<vector<char>> &v, vector<pair<int, int>> alreay, pair<int, int> cur, char *s)
{
	if (cur.first<0 || cur.first>v.size() - 1 || cur.second<0 || cur.second>v[0].size() - 1 || find(alreay.begin(), alreay.end(), cur) != alreay.end())
		return false;
	if (v[cur.first][cur.second] == *s)
	{
		if (*++s == '\0')
			return true;
		alreay.push_back(cur);
		pair<int, int> up, down, left, right;
		up = make_pair(cur.first - 1, cur.second);
		down = make_pair(cur.first + 1, cur.second);
		left = make_pair(cur.first, cur.second - 1);
		right = make_pair(cur.first, cur.second + 1);
		return search(v, alreay, up, s) || search(v, alreay, down, s) || search(v, alreay, left, s) || search(v, alreay, right, s);
	}
	else
		return false;
}

int main()
{
	Solution sol;
	char *matrix = "abcesfcsadee", *str = "abcb";
	cout << sol.hasPath(matrix, 3, 4, str);
	system("pause");
	return 0;
}
