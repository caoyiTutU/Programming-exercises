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

using namespace std;

class Solution {
public:
	bool isNumeric(char* string);
};

bool Solution::isNumeric(char* string)
{
	if (string == nullptr)
		return false;
	if (*string != '+'&&*string != '-' && (*string < 48) || (*string > 57))
		return false;
	++string;
	int flag = 0;
	while (*string != '\0')
	{
		if ((*string >= 48) && (*string <= 57))
			++string;
		else if (*string == '.')
		{
			if (++flag == 2)
				return false;
			++string;
		}
		else if (*string == 'E' || *string == 'e')
		{
			flag = 1;
			++string;
			if (*string != '+'&&*string != '-' && (*string < 48) || (*string > 57))
				return false;
			++string;
		}
		else
			return false;
	}
	return true;
}

int main()
{
	Solution sol;
	char str[] = "12e+4.3";
	cout << sol.isNumeric(str) << endl;
	system("pause");
	return 0;
}