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

using namespace std;

class ScaleSort {
public:
	vector<int> sortElement(vector<int> A, int n, int k);
private:
	void creatheap(vector<int> &ivec);
	void adjustheap(vector<int> &ivec, int index);
};

vector<int> ScaleSort::sortElement(vector<int> A, int n, int k)
{
	vector<int> result, heap(A.begin(), A.begin() + k);
	creatheap(heap);
	for (int i = 0;i <= n - k - 1;++i)
	{
		result.push_back(heap.front());
		heap.front() = A[i + k];
		adjustheap(heap, 0);
	}
	for (int j = 1;j <= k - 1;++j)
	{
		swap(heap.front(), heap.back());
		result.push_back(heap.back());
		heap.pop_back();
		adjustheap(heap, 0);
	}
	result.push_back(heap.front());
	return result;
}

void ScaleSort::creatheap(vector<int> &ivec)
{
	int end = ivec.size() - 1;
	for (int i = (end - 1) / 2;i >= 0;--i)
		adjustheap(ivec, i);
}

void ScaleSort::adjustheap(vector<int> &ivec,int index)
{
	int end = ivec.size() - 1, lchild = 2 * index + 1, rchild = 2 * index + 2;
	if (index <= (end - 1) / 2)
	{
		int minindex = index;
		if (lchild <= end&&ivec[lchild] < ivec[minindex])
			minindex = lchild;
		if (rchild <= end&&ivec[rchild] < ivec[minindex])
			minindex = rchild;
		if (minindex != index)
		{
			swap(ivec[minindex], ivec[index]);
			adjustheap(ivec, minindex);
		}
	}
}

int main()
{
	ScaleSort ssort;
	vector<int> ivec = { 2,1,4,3,6,5,8,7,10,9 }, result = ssort.sortElement(ivec, 10, 2);
	for (const auto &i : result)
		cout << i << endl;
	system("pause");
	return 0;
}