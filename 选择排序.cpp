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

class SelectionSort {
public:
	int* selectionSort(int* A, int n);
};

int* SelectionSort::selectionSort(int* A, int n)
{
	for (int i = 0;i < n - 1;++i)
	{
		int min = A[i], index = i;
		for (int j = i + 1;j < n;++j)
		{
			if (A[j] < min)
			{
				min = A[j];
				index = j;
			}
		}
		swap(A[i], A[index]);
	}
	return A;
}

int main()
{
	SelectionSort sel;
	int a[6] = {1,2,3,5,2,3};
	sel.selectionSort(a, 6);
	for (int i = 0;i < 6;++i)
		cout << a[i] << endl;
	system("pause");
	return 0;
}
