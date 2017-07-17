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

class Prior {
public:
	string findSmallest(vector<string> strs, int n);
};

string Prior::findSmallest(vector<string> strs, int n)
{
	string str;
	sort(strs.begin(), strs.end(), [](const string& s1, const string &s2) {return s1 + s2 < s2 + s1;});
	for (const auto &s : strs)
		str += s;
	return str;
}

int main()
{
	Prior pr;
	system("pause");
	return 0;
}
