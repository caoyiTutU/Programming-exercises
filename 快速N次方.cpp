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
#include<stack>
#include<queue>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>
#include<bitset>

using namespace std;

class QuickPower {
public:
	int getPower(int k, int N);
};

int QuickPower::getPower(int k, int N)
{
	bitset<32> bitvec(N);
	long long res = 1, curValue = k;
	for (int index = 0;index < bitvec.size();++index)
	{
		if (bitvec.test(index))
		{
			res *= curValue;
			res = res % 1000000007;
		}
		curValue = curValue*curValue;
		curValue = curValue % 1000000007;
	}
	return res;
}

int main()
{
	QuickPower qp;
	cout << qp.getPower(2, 14876069) << endl;
	system("pause");
	return 0;
}
