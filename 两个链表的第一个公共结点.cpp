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

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2);
};

ListNode* Solution::FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	ListNode *p = pHead1, *q = pHead2;
	vector<ListNode *>lvec1, lvec2;
	while (p != NULL)
	{
		lvec1.push_back(p);
		p = p->next;
	}
	while (q != NULL)
	{
		lvec2.push_back(q);
		q = q->next;
	}
	auto iter1 = lvec1.rbegin();
	auto iter2 = lvec2.rbegin();
	ListNode *result = NULL;
	while (iter1 != lvec1.rend() && iter2 != lvec2.rend() && *iter1 == *iter2)
	{
		result = *iter1;
		++iter1;
		++iter2;
	}
	return result;
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}