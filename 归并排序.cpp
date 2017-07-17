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
#include<iomanip>
#include<random>
#include<bitset>

using namespace std;

class MergeSort {
public:
	int* mergeSort(int* A, int n);
private:
	void partition(int lhs, int rhs, int* A);
	void mergesection(int lhs, int mid, int rhs, int* A);
};

int* MergeSort::mergeSort(int* A, int n)
{
	if (n < 1)
		return NULL;
	partition(0, n - 1, A);
	return A;
}

void MergeSort::partition(int lhs, int rhs, int* A)
{
	if (lhs < rhs)
	{
		int mid = (lhs + rhs) / 2;
		partition(lhs, mid, A);
		partition(mid + 1, rhs, A);
		mergesection(lhs, mid, rhs, A);
	}
}

void MergeSort::mergesection(int lhs, int mid, int rhs, int* A)
{
	int i = lhs, j = mid + 1;
	vector<int> ivec;
	while (i <= mid&&j <= rhs)
	{
		if (A[i] < A[j])
			ivec.push_back(A[i++]);
		else
			ivec.push_back(A[j++]);
	}
	while (i <= mid)
		ivec.push_back(A[i++]);
	while (j <= rhs)
		ivec.push_back(A[j++]);
	int k = 0;
	while (lhs <= rhs)
		A[lhs++] = ivec[k++];
}

int main() 
{
	int A[6] = { 1,2,3,5,2,3 }, n = 6, *p;
	MergeSort mer;
	p = mer.mergeSort(A, n);
	for (int i = 0;i < 6;++i)
		cout << p[i] << endl;
	system("pause");
	return 0;
}