#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<set>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum);
private:
	vector<pair<int, int>> pvec;
	vector<int> ivec;
};

vector<int> Solution::FindNumbersWithSum(vector<int> array, int sum)
{
	if (array.size() < 2)
		return ivec;
	auto iter_beg = array.begin();
	int number = sum - *iter_beg;
	auto iter_end = upper_bound(iter_beg, array.end(), number) - 1;
	while (iter_end > iter_beg)
	{
		if (*iter_end == number)
		{
			pvec.push_back(make_pair(*iter_beg, number));
			if (iter_end - iter_beg > 2)
			{
				vector<int> temp;
				copy(iter_beg + 1, iter_end, back_inserter(temp));
				return FindNumbersWithSum(temp, sum);
			}
			break;
		}
		++iter_beg;
		number = sum - *iter_beg;
		iter_end = upper_bound(iter_beg, iter_end + 2, number) - 1;
	}
	if (pvec.empty())
		return ivec;
	vector<pair<int,int>> vec;
	unsigned i = 0;
	for (const auto &v : pvec)
		vec.push_back(make_pair(v.first*v.second, i++));
	sort(vec.begin(), vec.end(), [](const pair<int, int> p1, const pair<int, int> p2) {return p1.first < p2.first;});
	i = vec.at(0).second;
	ivec.push_back(pvec.at(i).first);
	ivec.push_back(pvec.at(i).second);
	return ivec;
}

int main()
{
	Solution sol;
	vector<int> ivec = { 6,7,8,9,10 };
	vector<int> v = sol.FindNumbersWithSum(ivec, 16);
	cout << v.at(0) << "  " << v.at(1) << endl;
	system("pause");
	return 0;
}