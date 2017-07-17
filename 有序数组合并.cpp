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

class Merge {
public:
	int* mergeAB(int* A, int* B, int n, int m);
};

int* Merge::mergeAB(int* A, int* B, int n, int m)
{
	int indexa = n - 1, indexb = m - 1, index = n + m - 1;
	while (indexa >= 0 && indexb >= 0)
	{
		if (A[indexa] >= B[indexb])
			A[index--] = A[indexa--];
		else
			A[index--] = B[indexb--];
	}
	while (indexa >= 0)
		A[index--] = A[indexa--];
	while (indexb >= 0)
		A[index--] = B[indexb--];
	return A;
}

int main()
{
	Merge mer;
	int A[6] = { 2,4,6,0,0,0 }, B[3] = { 1,3,5 };
	int *p;
	p = mer.mergeAB(A, B, 3, 3);
	for (int i = 0;i < 6;++i)
		cout << p[i] << endl;
	system("pause");
	return 0;
}