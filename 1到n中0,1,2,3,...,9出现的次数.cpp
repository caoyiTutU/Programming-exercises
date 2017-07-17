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
#include<math.h>

using namespace std;

int count(int n, int x)
{
	int cnt = 0, k;
	for (int i = 1;k = n / i;i *= 10)
	{
		cnt += k / 10 * i;
		int m = k % 10;
		if (m > x)
			cnt += i;
		else if (m == x)
			cnt += n - i*k + 1;
		if (x == 0)
		{
			cnt -= i;
			if (k / 100 == 0)
				i *= 10;
		}
	}
	return cnt;
}

int main()
{
	int n = 999, x;
	while (cin >> x)
		cout << count(n, x) << endl;
	system("pause");
	return 0;
}