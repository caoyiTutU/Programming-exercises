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
	void Insert(int num);
	double GetMedian();
private:
	vector<int> ivec;
};

void Solution::Insert(int num)
{
	auto iter = find_if(ivec.begin(), ivec.end(), [num](const int i) {return i > num;});
	ivec.insert(iter, num);
}

double Solution::GetMedian()
{
	unsigned len = ivec.size();
	if (len == 0)
		return 0;
	if (len % 2)
		return ivec[len / 2];
	else
		return double((ivec[(len - 1) / 2] + ivec[(len - 1) / 2 + 1])) / 2;
}
int main()
{
	Solution sol;
	system("pause");
	return 0;
}
