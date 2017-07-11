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
	int minNumberInRotateArray(vector<int> rotateArray);
};

int Solution::minNumberInRotateArray(vector<int> rotateArray)
{
	unsigned length = rotateArray.size();
	unsigned mid = length / 2;
	int min;
	if (length == 0)
		return 0;
	if (rotateArray[0] < rotateArray[length - 1])
		return rotateArray[0];
	if (rotateArray[mid] > rotateArray[0])
	{
		for (unsigned i = mid;i < length-1;++i)
		{
			if (rotateArray[i] > rotateArray[i + 1])
			{
				min = rotateArray[i + 1];
				break;
			}
		}
	}
	else
	{
		unsigned j = 0;
		for (;j < length - 1;++j)
		{
			if (rotateArray[j] > rotateArray[j + 1])
			{
				min = rotateArray[j + 1];
				break;
			}
		}
		if (j == length - 1)
			return rotateArray[0];
	}
	return min;
}
int main()
{
	Solution sol;
	vector<int> vec = { 4,5,6,7,8,9,2,3 };
	cout << sol.minNumberInRotateArray(vec) << endl;
	system("pause");
	return 0;
}