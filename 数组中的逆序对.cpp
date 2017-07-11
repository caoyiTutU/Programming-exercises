#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<set>

using namespace std;

//归并排序

class Solution {
public:
	int InversePairs(vector<int> data);
	void MergeSort(vector<int>& data, int first, int end);
	void MergeArray(vector<int>& data, int first, int mid, int end);
	long count;
	
};
int Solution::InversePairs(vector<int> data)
{
	count = 0;
	unsigned l = data.size();
	if (l <= 1)
		return 0;
	MergeSort(data, 0, l - 1);
	return count % 1000000007;
}
void Solution::MergeSort(vector<int>& data, int first, int end) 
{
		if (first < end)
		{
			int mid = (first + end) / 2;
			MergeSort(data, first, mid);
			MergeSort(data, mid + 1, end);
			MergeArray(data, first, mid, end);
		}
}
void Solution::MergeArray(vector<int>& data, int first, int mid, int end)
{
	    vector<int> tmp;
		int i = first;int m = mid;
		int j = mid + 1;int n = end;
		while (i <= m && j <= n)
		{
			if (data[i] > data[j]) 
			{
				tmp.push_back(data[i++]);
				count += n - j + 1;
			}
			else 
			{
				tmp.push_back(data[j++]);
			}
		}
		while (i <= m)
			tmp.push_back(data[i++]);
		while (j <= n)
			tmp.push_back(data[j++]);

		//更新data数组
		int k = 0;
		for (int i = first; i <= end; i++)
			data[i] = tmp[k++];
}

int main()
{
	Solution sol;
	vector<int> ivec = { 1,54,2,45,7,4,3,897,54,6,34,76,43,23 };
	cout << sol.InversePairs(ivec) << endl;
	system("pause");
	return 0;
}