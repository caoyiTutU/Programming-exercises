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

class SlideWindow {
public:
	vector<int> slide(vector<int> arr, int n, int w);
};

vector<int> SlideWindow::slide(vector<int> arr, int n, int w)
{
	vector<int> res;
	deque<int> ideq;
	for (int i = 0;i < n;++i)
	{
		while (!ideq.empty() && arr[ideq.back()] <= arr[i])
			ideq.pop_back();
		ideq.push_back(i);
		if (i + 1 >= w)
		{
			while (ideq.front() < i + 1 - w)
				ideq.pop_front();
			res.push_back(arr[ideq.front()]);
		}
	}
	return res;
}

int main()
{
	SlideWindow sw;
	vector<int> ivec = { 4,3,5,4,3,3,6,7 }, res = sw.slide(ivec, 8, 3);
	for (const auto &i : res)
		cout << i << endl;
	system("pause");
	return 0;
}
