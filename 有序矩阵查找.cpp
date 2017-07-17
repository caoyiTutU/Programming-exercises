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

class Finder {
public:
	bool findX(vector<vector<int> > mat, int n, int m, int x);
};

bool Finder::findX(vector<vector<int>> mat, int n, int m, int x)
{
	pair<int, int> index = make_pair(0, m - 1);
	while (index.first <= n - 1 && index.second >= 0)
	{
		if (mat[index.first][index.second] > x)
			--index.second;
		else if (mat[index.first][index.second] < x)
			++index.first;
		else
			return true;
	}
	return false;	
}

int main()
{
	Finder fd;
	vector < vector<int >> mat = { {1, 2, 3 }, { 4,5,6 }, { 7,8,9 }};
	cout << fd.findX(mat, 3, 3, 11) << endl;
 	system("pause");
	return 0;
}
