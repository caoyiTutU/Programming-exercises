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

class TwoStack {
public:
	vector<int> twoStack(vector<int> ope, int n);
private:
	stack<int> pushsta, popsta;
};

vector<int> TwoStack::twoStack(vector<int> ope, int n)
{
	vector<int> ivec;
	for (const auto &i : ope)
	{
		if (i > 0)
			pushsta.push(i);
		else if (i == 0)
		{
			if (popsta.empty())
			{
				int size = pushsta.size();
				for (int j = 0;j < size;++j)
				{
					popsta.push(pushsta.top());
					pushsta.pop();
				}
			}
			ivec.push_back(popsta.top());
			popsta.pop();
		}
	}
	return ivec;
}

int main()
{
	TwoStack ts;
	vector<int> v = { 1,2,3,0,4,0 }, result = ts.twoStack(v, 6);
	for (const auto &i : result)
		cout << i << endl;
	system("pause");
	return 0;
}
