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

class Translation {
public:
	string stringTranslation(string A, int n, int len);
};

//STL泛型算法直接旋转

//string Translation::stringTranslation(string A, int n, int len)
//{
//	if (len >= n)
//		return A;
//	rotate(A.begin(), A.begin() + len, A.end());
//	return A;
//}

//局部逆序

string Translation::stringTranslation(string A, int n, int len)
{
	if (len >= n)
		return A;
	reverse(A.begin(), A.begin() + len);
	reverse(A.begin() + len, A.end());
	reverse(A.begin(), A.end());
	return A;
}

int main()
{
	Translation tr;
	system("pause");
	return 0;
}
