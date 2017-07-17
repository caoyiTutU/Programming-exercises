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

class Solution {
public:
	int getLessIndex(vector<int> arr);
private:
	int binarySearch(int lhs, int rhs, vector<int> &arr);
};

int Solution::getLessIndex(vector<int> arr)
{
	if (arr.empty())
		return -1;
	else if (arr.size() == 1)
		return 0;
	else
	{
		if (arr[0] < arr[1])
			return 0;
		else if (arr[arr.size() - 1] < arr[arr.size() - 2])
			return arr.size() - 1;
		else
			return binarySearch(1, arr.size() - 2, arr);
	}
}

int Solution::binarySearch(int lhs, int rhs, vector<int> &arr)
{
	if (lhs == rhs)
		return lhs;
	int mid = lhs + (rhs - lhs) / 2;
	if (arr[mid] > arr[mid - 1])
		return binarySearch(lhs, mid - 1, arr);
	else if (arr[mid] > arr[mid + 1])
		return binarySearch(mid + 1, rhs, arr);
	else
		return mid;
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
