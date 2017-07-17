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

class QuickSort {
public:
	int* quickSort(int* A, int n);
private:
	void eachsort(int lhs, int rhs, int* A);
};

int* QuickSort::quickSort(int* A, int n)
{
	if (n < 1)
		return NULL;
	eachsort(0, n - 1, A);
	return A;
}

void QuickSort::eachsort(int lhs, int rhs, int* A)
{
	if (lhs < rhs)
	{
		int L = lhs;
		for (int i = lhs;i <= rhs;++i)
			if (A[i] <= A[rhs])
				swap(A[i], A[L++]);
		int index = L - 1;
		if (index > lhs)
			eachsort(lhs, index - 1, A);
		if (index < rhs)
			eachsort(index + 1, rhs, A);
	}
}

int main() 
{
	int A[6] = { 1,2,3,5,2,3 }, n = 6, *p;
	QuickSort qu;
	p = qu.quickSort(A, n);
	for (int i = 0;i < 6;++i)
		cout << p[i] << endl;
	system("pause");
	return 0;
}