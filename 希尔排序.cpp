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

class ShellSort {
public:
	int* shellSort(int* A, int n);
};

int* ShellSort::shellSort(int* A, int n)
{
	int grep = n / 2;
	while (grep != 0)
	{
		for (int i = grep;i < n;++i)
		{
			int j = i;
			while (j >= grep)
			{
				if (A[j] < A[j - grep])
				{
					swap(A[j], A[j - grep]);
					j = j - grep;
				}
				else
					break;
			}
		}
		grep /= 2;
	}
	return A;
}

int main() 
{
	int A[6] = { 1,2,3,5,2,3 }, n = 6, *p;
	ShellSort shes;
	p = shes.shellSort(A, n);
	for (int i = 0;i < 6;++i)
		cout << p[i] << endl;
	system("pause");
	return 0;
}