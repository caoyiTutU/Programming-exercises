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

class Reverse {
public:
	string reverseSentence(string A, int n);
};

string Reverse::reverseSentence(string A, int n)
{
	vector<string> svec;
	istringstream in(A);
	string str, result;
	while (in >> str)
		svec.push_back(str);
	reverse(svec.begin(), svec.end());
	for (auto iter = svec.begin();iter != svec.end();++iter)
	{
		result += *iter;
		if (iter != svec.end() - 1)
			result += " ";
	}
	return result;
}

int main()
{
	Reverse re;
	string str = "dog loves pig";
	cout << re.reverseSentence(str, 13) << endl;
	system("pause");
	return 0;
}
