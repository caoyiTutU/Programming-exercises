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

using namespace std;

class InsertionSort {
public:
	int* insertionSort(int* A, int n);
};

int* InsertionSort::insertionSort(int* A, int n)
{
	for (int i = 1;i < n;++i)
	{
		for (int j = i-1;j >= 0;--j)
		{
			if (A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
			else
				break;
		}
	}
	return A;
}

int main()
{
	InsertionSort ins;
	int a[6] = {1,2,3,5,2,3};
	ins.insertionSort(a, 6);
	for (int i = 0;i < 6;++i)
		cout << a[i] << endl;
	system("pause");
	return 0;
}
