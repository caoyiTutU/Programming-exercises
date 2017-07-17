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

class ThreeColor {
public:
	vector<int> sortThreeColor(vector<int> A, int n);
};

vector<int> ThreeColor::sortThreeColor(vector<int> A, int n)
{
	int L0 = 0, L2 = n - 1, index = 0;
	while (index <= L2)
	{
		if (A[index] == 0)
			swap(A[L0++], A[index++]);
		else if (A[index] == 2)
			swap(A[L2--], A[index]);
		else
			++index;
	}
	return A;
}

int main()
{
	ThreeColor tc;
	vector<int> A = { 0,1,1,0,2,2 }, B = tc.sortThreeColor(A, 6);
	for (const auto &i : B)
		cout << i << endl;
 	system("pause");
	return 0;
}
