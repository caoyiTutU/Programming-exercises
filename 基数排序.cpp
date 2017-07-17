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

class RadixSort {
public:
	int* radixSort(int* A, int n);
};

int* RadixSort::radixSort(int* A, int n)
{
	size_t maxsize = 0;
	for (int i = 0;i < n;++i)
		maxsize = max(to_string(A[i]).size(), maxsize);
	vector<string> svec;
	for (int j = 0;j < n;++j)
	{
		string s = to_string(A[j]);
		int num0 = maxsize - s.size();
		s.insert(s.begin(), num0, '0');
		svec.push_back(s);
	}
	for (int k = 1;k <= maxsize;++k)
	{
		map<int, vector<string>> imap;
		for (int i = 0;i < n;++i)
			imap[svec[i][maxsize - k]].push_back(svec[i]);
		svec.clear();
		for (auto miter = imap.begin();miter != imap.end();++miter)
			for (auto viter = miter->second.begin();viter != miter->second.end();++viter)
				svec.push_back(*viter);
	}
	int index = 0;
	for (const auto &s : svec)
		A[index++] = stoi(s);
	return A;
}

int main() 
{
	RadixSort rsort;
	int A[8] = { 564,2,41,5,2,3,53,324 };
	int *p = rsort.radixSort(A, 8);
	for (int i = 0;i < 8;++i)
		cout << p[i] << endl;
	system("pause");
	return 0;
}