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
	ListNode* deleteDuplication(ListNode* pHead);
};

ListNode* Solution::deleteDuplication(ListNode* pHead)
{
	ListNode* p = pHead;
	long long v;
	int flag = 0;
	while (p!=NULL && p->next != NULL)
	{
		if (p->val == p->next->val)
		{
			v = p->val;
			while (p != NULL && p->val == v)
			{
				ListNode* q = p;
				p = p->next;
				delete q;
			}
		}
		else
			break;
	}
	if (p == NULL)
		return NULL;
	pHead = p;
	ListNode* r = p;
	p = p->next;
	while (p!=NULL && p->next != NULL)
	{
		if (p->val == p->next->val)
		{
			v = p->val;
			while (p != NULL && p->val == v)
			{
				ListNode* q = p;
				p = p->next;
				r->next = p;
				delete q;
			}
		}
		else
		{
			r = r->next;
			p = p->next;
		}
	}
	return pHead;
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}