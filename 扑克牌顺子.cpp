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
	bool IsContinuous(vector<int> numbers);
};

bool Solution::IsContinuous(vector<int> numbers)
{
	unsigned len = numbers.size();
	if (len < 2 || len >13)
		return false;
	sort(numbers.begin(), numbers.end());
	auto iter = find_if(numbers.begin(), numbers.end(), [](const int &i) {return i > 0;});
	unsigned num_0 = iter - numbers.begin();
    if (num_0 >= len - 1)
		return true;
	for (unsigned j = 0;j < num_0;++j)
	{
		int flag = 0;
		while (iter != numbers.end() - 1)
		{
			if (*(iter + 1) - *iter == 1)
				++iter;
			else
			{
				iter = numbers.insert(iter + 1, *iter + 1);
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			continue;
		return true;
	}
	int temp = numbers.at(num_0);
	for (auto beg = numbers.begin() + num_0+1;beg != numbers.end();++beg)
	{
		if (*beg != ++temp)
			return false;
	}
	return true;
}

int main()
{
	Solution sol;
	vector<int> numbers = { 1,5,0,0,6,0,0,9 };
	cout << sol.IsContinuous(numbers) << endl;
	system("pause");
	return 0;
}