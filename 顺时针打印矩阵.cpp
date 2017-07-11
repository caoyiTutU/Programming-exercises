#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix);
private:
	vector<int> ivec;
	vector<vector<int>> matrix1;
	vector<int> v;
};

vector<int> Solution::printMatrix(vector<vector<int>> matrix)
{
	unsigned line = matrix.size();
	if (line == 0)
		return ivec;
	unsigned row = matrix[0].size();
	if (row == 0)
		return ivec;
	if (line == 1 || row == 1)
	{
		for (auto &i1 : matrix)
			for (auto &i2 : i1)
				ivec.push_back(i2);
		return ivec;
	}
	else if (line == 2 || row == 2)
	{
		for (auto &i1 : matrix[0])
			ivec.push_back(i1);
		if (line == 2)
		{
			for (auto iter = matrix[1].rbegin();iter != matrix[1].rend();++iter)
				ivec.push_back(*iter);
			return ivec;
		}
		for (unsigned i = 1;i < line;++i)
			ivec.push_back(matrix[i].back());
		for (int j = line - 1;j > 0;--j)
			ivec.push_back(matrix[j].front());
		return ivec;
	}
	else
	{
		for (auto &i1 : matrix[0])
			ivec.push_back(i1);
		for (unsigned i = 1;i < line - 1;++i)
			ivec.push_back(matrix[i].back());
		for (auto iter = matrix[line - 1].rbegin();iter != matrix[line - 1].rend();++iter)
			ivec.push_back(*iter);
		for (int i = line - 2;i > 0;--i)
			ivec.push_back(matrix[i].front());
		matrix1.clear();
		for (unsigned j = 1;j < line - 1;++j)
		{
			for (auto iter1 = matrix[j].begin() + 1;iter1 != matrix[j].end() - 1;++iter1)
				v.push_back(*iter1);
			matrix1.push_back(v);
			v.clear();
		}
		return printMatrix(matrix1);
	}
}

int main()
{
	Solution sol;
	vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<int> ivec;
	ivec = sol.printMatrix(matrix);
	for (auto &i : ivec)
	{
		cout << i << endl;
	}
	system("pause");
	return 0;
}