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

class TwoStacks {
public:
	vector<int> twoStacksSort(vector<int> numbers);
};

vector<int> TwoStacks::twoStacksSort(vector<int> numbers)
{
	vector<int> ivec;
	int data;
	while (!numbers.empty())
	{
		data = numbers.back();
		numbers.pop_back();
		while (!ivec.empty() && data > ivec.back())
		{
			numbers.push_back(ivec.back());
			ivec.pop_back();
		}
		ivec.push_back(data);
	}
	return numbers;
}

int main()
{
	
	system("pause");
	return 0;
}
