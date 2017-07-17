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

class BubbleSort {
public:
	int* bubbleSort(int* A, int n);
};

int* BubbleSort::bubbleSort(int* A, int n)
{
	for(int i=0;i<n-1;++i)
		for (int j = 0;j < n - i - 1;++j)
		{
			if (A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
		}
	return A;
}

int main()
{
	BubbleSort bub;
	int a[6] = {1,2,3,5,2,3};
	bub.bubbleSort(a, 6);
	for (int i = 0;i < 6;++i)
		cout << a[i] << endl;
	system("pause");
	return 0;
}
