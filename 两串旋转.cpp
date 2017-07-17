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

class Rotation {
public:
	bool chkRotation(string A, int lena, string B, int lenb);
private:
	void nextarray(const string &str, vector<int> &ivec);
};

bool Rotation::chkRotation(string A, int lena, string B, int lenb)
{
	if (lena != lenb || lena == 0)
		return false;
	string AA = A + A;
	vector<int> ivec(lenb, -1);
	nextarray(B, ivec);
	int index = AA.find(B[0]);
	while (index != string::npos&&index <= lena)
	{
		int i = index, count = 0;
		for (int j = 0;j < lenb;++j)
		{
			if (AA[i++] == B[j])
				++count;
			else
				break;
		}
		if (count == lenb)
			return true;
		else
			index += count - ivec[count];
	}
	return false;
}

void Rotation::nextarray(const string &str, vector<int> &ivec)
{
	if (ivec.size() < 2)
		return;
	ivec[1] = 0;
	int L = 0;
	for (int i = 2;i < str.size();++i)
	{
		while (L > 0 && str[L] != str[i - 1])
			L = ivec[L];
		if (str[L] == str[i - 1])
			++L;
		ivec[i] = L;
	}
}

int main()
{
	Rotation ro;
	string A = "cdab", B = "abdc";
	cout << ro.chkRotation(A, 4, B, 4) << endl;
	system("pause");
	return 0;
}
