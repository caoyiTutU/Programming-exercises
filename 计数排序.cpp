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

class CountingSort {
public:
	int* countingSort(int* A, int n);
};

int* CountingSort::countingSort(int* A, int n)
{
	map<int, vector<int>> imap;
	for (int i = 0;i < n;++i)
		imap[A[i]].push_back(A[i]);
	int j = 0;
	for (auto miter = imap.begin();miter != imap.end();++miter)
		for (auto viter = miter->second.begin();viter != miter->second.end();++viter)
			A[j++] = *viter;
	return A;
}

int main() 
{
	CountingSort csort;
	int A[6] = { 1, 2, 3, 5, 2, 3 };
	int *p = csort.countingSort(A, 6);
	for (int i = 0;i < 6;++i)
		cout << p[i] << endl;
	system("pause");
	return 0;
}