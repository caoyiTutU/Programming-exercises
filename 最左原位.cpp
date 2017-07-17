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

class Find {
public:
	int findPos(vector<int> arr, int n);
};

int Find::findPos(vector<int> arr, int n)
{
	if (n < 1 || arr[0] > n - 1 || arr[n - 1] < 0)
		return -1;
	int res = -1, lhs = 0, rhs = n - 1;
	while (lhs < rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (arr[mid] > mid)
			rhs = mid - 1;
		else if (arr[mid] < mid)
			lhs = mid + 1;
		else
		{
			res = mid;
			rhs = mid - 1;
		}
	}
	if (arr[lhs] == lhs)
		res = lhs;
	return res;
}

int main()
{
	Find fi;
	vector<int> ivec = { -1,0,2,3 };
	cout << fi.findPos(ivec, 4) << endl;
	system("pause");
	return 0;
}
