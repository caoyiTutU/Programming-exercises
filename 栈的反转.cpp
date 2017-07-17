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

class StackReverse {
public:
	void reverseStack(vector<int> &A, int n);
private:
	int get(vector<int> &A);
};

int StackReverse::get(vector<int> &A)
{
	int result = A.back();
	A.pop_back();
	if (A.empty())
		return result;
	else
	{
		int value = get(A);
		A.push_back(result);
		return value;
	}
}

void StackReverse::reverseStack(vector<int> &A, int n)
{
	if (A.empty())
		return;
	int temp = get(A);
	reverseStack(A, n);
	A.push_back(temp);
}

int main()
{
	StackReverse sr;
	vector<int> ivec = { 4,3,2,1 };
	sr.reverseStack(ivec, 4);
	for (const auto &i : ivec)
		cout << i << endl;
	system("pause");
	return 0;
}
