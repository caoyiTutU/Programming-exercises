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

class Replacement {
public:
	string replaceSpace(string iniString, int length);
};

string Replacement::replaceSpace(string iniString, int length)
{
	string str;
	for (const auto &c : iniString)
	{
		if (isspace(c))
			str += "%20";
		else
			str += c;
	}
	return str;
}

int main()
{
	Replacement re;
	string s = "Mr John Smith";
	cout << re.replaceSpace(s, 13) << endl;
	system("pause");
	return 0;
}
