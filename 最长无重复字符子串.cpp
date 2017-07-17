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

class DistinctSubstring {
public:
	int longestSubstring(string A, int n);
};

int DistinctSubstring::longestSubstring(string A, int n)
{
	unordered_map<char, int> cumap;
	vector<int> s(n, 1);
	cumap[A[0]] = 0;
	for (int i = 1;i < n;++i)
	{
		if ((cumap[A[i]] == 0 && A[i] != A[0]) || (cumap[A[i]] < i - s[i - 1]))
			s[i] = s[i - 1] + 1;
		else
			s[i] = i - cumap[A[i]];
		cumap[A[i]] = i;
	}
	return *max_element(s.begin(), s.end());
}

int main()
{
	DistinctSubstring dis;
	string str = "aabcb";
	cout << dis.longestSubstring(str, 5) << endl;
	system("pause");
	return 0;
}
