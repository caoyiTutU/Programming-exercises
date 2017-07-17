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
#include<stack>
#include<iomanip>
#include<random>
#include<bitset>

using namespace std;

class HeapSort {
public:
	int* heapSort(int* A, int n);
private:
	void buildheap(int* A, int end);
	void adjustheap(int* A, int index, int end);
};

int* HeapSort::heapSort(int* A, int n)
{
	if (n == 0)
		return NULL;
	buildheap(A, n - 1);
	for (int i = n - 1;i >= 1;--i)
	{
		swap(A[0], A[i]);
		adjustheap(A, 0, i - 1);
	}
	return A;
}

void HeapSort::buildheap(int* A, int end)
{
	//初始构建堆时从非叶节点的最大序号开始依次往前调整
	for (int i = (end - 1) / 2;i >= 0;--i)  
		adjustheap(A, i, end);
}

void HeapSort::adjustheap(int* A, int index, int end)
{
	//左孩子的节点序号为2 * index + 1，右孩子的节点序号为2 * index + 2
	int lchild = 2 * index + 1, rchild = 2 * index + 2, max = index;
	if (index <= (end - 1) / 2)
	{
		if (lchild <= end&&A[lchild] > A[max])
			max = lchild;
		if (rchild <= end&&A[rchild] > A[max])
			max = rchild;
		if (max != index)
		{
			swap(A[index], A[max]);
			adjustheap(A, max, end);
		}
	}
}

int main() 
{
	HeapSort heaps;
	system("pause");
	return 0;
}