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

class Parenthesis {
public:
	bool chkParenthesis(string A, int n);
};

bool Parenthesis::chkParenthesis(string A, int n)
{
	int num = 0;
	for (const auto &c : A)
	{
		if (c == '(')
			++num;
		else if (c == ')')
			--num;
		else
			if (num == 0)
				return false;
		if (num < 0)
			return false;
	}
	if (num == 0)
		return true;
	else
		return false;
}

int main()
{
	Parenthesis pa;
	system("pause");
	return 0;
}
