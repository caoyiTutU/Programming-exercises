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

class Gap {
public:
	int maxGap(vector<int> A, int n);
};

int Gap::maxGap(vector<int> A, int n)
{
	if (n < 2)
		return 0;
	set<int> iset;
	for (const auto &i : A)
		iset.insert(i);
	auto pre = iset.begin();
	int max = 0;
	for (auto iter = ++iset.begin();iter != iset.end();++iter)
	{
		if (*iter - *pre > max)
			max = *iter - *pre;
		++pre;
	}
	return max;
}

int main()
{
	Gap ga;
	vector <int> A = { 1,2,5,4,6};
	cout << ga.maxGap(A,5) << endl;
 	system("pause");
	return 0;
}
