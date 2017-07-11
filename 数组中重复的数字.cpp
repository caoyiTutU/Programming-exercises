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

using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication);
};

bool Solution::duplicate(int numbers[], int length, int* duplication)
{
	if (length < 2)
		return false;
	map<int, int> imap;
	for (int i = 0;i < length;++i)
	{
		++imap[numbers[i]];
		if (imap[numbers[i]] == 2)
		{
			*duplication = numbers[i];
			return true;
		}
	}
	return false;
}

int main()
{
	Solution sol;
	int numbers[] = { 2,3,1,0,2,5,3 };
	int *result = numbers;
	sol.duplicate(numbers, 7, result);
	cout << *result << endl;
	system("pause");
	return 0;
}