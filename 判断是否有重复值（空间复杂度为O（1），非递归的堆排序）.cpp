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

using namespace std;

class Checker {
public:
	bool checkDuplicate(vector<int> a, int n);
private:
	void creatheap(vector<int> &ivec, int end);
	void adjustheap(vector<int> &ivec, int index, int end);
};

bool Checker::checkDuplicate(vector<int> a, int n)
{
	if (n == 0 || n == 1)
		return false;
	creatheap(a, n - 1);
	for (int i = n - 1;i >= 1;--i)
	{
		swap(a[i], a[0]);
		adjustheap(a, 0, i - 1);
	}
	int pre = a[0];
	for (auto iter = a.begin() + 1;iter != a.end();++iter)
	{
		if (*iter == pre)
			return false;
		else
			pre = *iter;
	}
	return true;
}

void Checker::creatheap(vector<int> &ivec, int end)
{
	for (int i = (end - 1) / 2;i >= 0;--i)
		adjustheap(ivec, i, end);
}

void Checker::adjustheap(vector<int> &ivec, int index, int end)
{
	int lchild = 2 * index + 1, rchild = 2 * index + 2;
	while (index <= (end - 1) / 2)
	{
		int max = index;
		if (lchild <= end&&ivec[lchild] > ivec[max])
			max = lchild;
		if (rchild <= end&&ivec[rchild] > ivec[max])
			max = rchild;
		if (max != index)
		{
			swap(ivec[index], ivec[max]);
			index = max;
			lchild = 2 * index + 1;
			rchild = 2 * index + 2;
		}
		else
			break;
	}
}

int main()
{
	Checker che;
	system("pause");
	return 0;
}