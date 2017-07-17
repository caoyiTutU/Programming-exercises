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
#include<stack>
#include<queue>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>
#include<bitset>

using namespace std;

class LeftMostAppearance {
public:
	int findPos(vector<int> arr, int n, int num);
};

int LeftMostAppearance::findPos(vector<int> arr, int n, int num)
{
	if (arr.empty())
		return -1;
	int lhs = 0, rhs = n - 1, res = -1;
	while (lhs < rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (arr[mid] < num)
			lhs = mid + 1;
		else if (arr[mid] > num)
			rhs = mid - 1;
		else
		{
			res = mid;
			rhs = mid - 1;
		}
	}
	if (arr[lhs] == num)
		res = lhs;
	return res;
}


int main()
{
	LeftMostAppearance lm;
	system("pause");
	return 0;
}
