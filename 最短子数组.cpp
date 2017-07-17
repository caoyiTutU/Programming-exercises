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
#include<math.h>
#include<stack>
#include<iomanip>
#include<random>
#include<bitset>
#include<regex>
#include<unordered_set>

using namespace std;

class Subsequence {
public:
	int shortestSubsequence(vector<int> A, int n);
};

int Subsequence::shortestSubsequence(vector<int> A, int n)
{
	if (n == 0)
		return 0;
	int max = A[0], min = A[n - 1];
	vector<int> maxindex, minindex;
	for (int i = 0;i <= n - 1;++i)
	{
		if (A[i] > max)
			max = A[i];
		else if (A[i] < max)
			maxindex.push_back(i);
	}
	for (int j = n - 1;j >= 0;--j)
	{
		if (A[j] < min)
			min = A[j];
		else if (A[j] > min)
			minindex.push_back(j);
	}
	if (maxindex.empty() || minindex.empty())
		return 0;
	return maxindex.back() - minindex.back() + 1;
}

int main()
{
	Subsequence ss;
	vector <int> A = { 1,2,10,1,8,9};
	cout << ss.shortestSubsequence(A, 6) << endl;
 	system("pause");
	return 0;
}
