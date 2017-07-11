#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>

using namespace std;

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n);
	unsigned int_size(int m);
private:
	int count = 0;
};

int Solution::NumberOf1Between1AndN_Solution(int n)
{
	unsigned n_size = int_size(n);  //����λ
	while (n_size != 1)
	{
		int k = pow(10, n_size - 1);  //����4253,k=1000
		int hnum = n / k;  //���λ����
		int single_count = k - pow(9, n_size - 1);//000-999�к��ж��ٸ�1
		count += single_count;
		if (hnum == 1)
		{
			count += n - k + 1;
			return count;
		}
		else
			count += k + (hnum - 2)*single_count;
		int next_num = n - k*hnum;
		if (next_num == 0)
			return count;
		else
		{
			n = next_num;
			--n_size;
		}
	}
	++count;
	return count;
}

unsigned Solution::int_size(int m)
{
	unsigned size = 0;
	int k = 1;
	while (m / k != 0)
	{
		++size;
		if (k == 1000000000)
			break;
		k *= 10;
	}
	return size;
}

int main()
{
	Solution sol;
	cout << sol.NumberOf1Between1AndN_Solution(55) << endl;
	system("pause");
	return 0;
}