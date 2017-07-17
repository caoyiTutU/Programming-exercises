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
#include<unordered_map>
#include<memory>

using namespace std;

class Transform {
public:
	bool chkTransform(string A, int lena, string B, int lenb);
};

bool Transform::chkTransform(string A, int lena, string B, int lenb)
{
	if (lena != lenb)
		return false;
	map<char, int> cumap_a, cumap_b;
	for (const auto &a : A)
		++cumap_a[a];
	for (const auto &b : B)
		++cumap_b[b];
	auto iter_a = cumap_a.begin(), iter_b = cumap_b.begin();
	while (iter_a != cumap_a.end() && iter_b != cumap_b.end())
	{
		if (iter_a->first != iter_b->first || iter_a->second != iter_b->second)
			return false;
		++iter_a;
		++iter_b;
	}
	return true;
}

int main()
{
	Transform tr;
	string A = "abc", B = "bca";
	cout << tr.chkTransform(A, 3, B, 3) << endl;
	system("pause");
	return 0;
}
