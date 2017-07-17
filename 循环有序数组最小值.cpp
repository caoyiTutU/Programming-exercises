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

class MinValue {
public:
	int getMin(vector<int> arr, int n);
};

int MinValue::getMin(vector<int> arr, int n)
{
	if (n == 0)
		return -1;
	if (arr[0] < arr[n - 1])
		return arr[0];
	int lhs = 0, rhs = n - 1;
	while (lhs < rhs)
	{
		if (lhs == rhs - 1)
			break;
		int mid = lhs + (rhs - lhs) / 2;
		if (arr[mid] < arr[lhs])
			rhs = mid;
		else if (arr[mid] > arr[rhs])
			lhs = mid;
		else
		{
			int minElement = arr[lhs];
			for (int i = lhs + 1;i <= rhs;++i)
				if (arr[i] < minElement)
					minElement = arr[i];
			return minElement;
		}
	}
	return min(arr[lhs], arr[rhs]);
}

int main()
{
	vector<int> ivec = { 6,2,4,5 };
	MinValue mv;
	cout << mv.getMin(ivec, 4) << endl;
	system("pause");
	return 0;
}