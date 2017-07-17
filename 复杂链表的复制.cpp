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
#include<stack>
#include<queue>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>

using namespace std;

struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead);
};

RandomListNode* Solution::Clone(RandomListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	RandomListNode *p = pHead;
	while (p != NULL)
	{
		RandomListNode *q = new RandomListNode(p->label);
		q->next = p->next;
		p->next = q;
		p = p->next->next;
	}
	p = pHead;
	while (p != NULL)
	{
		RandomListNode *r = p->next;
		if (p->random != NULL)
			r->random = p->random->next;
		p = p->next->next;
	}
	p = pHead;
	RandomListNode *head = p->next, *tail = p->next, *ptail = p;
	p = p->next->next;
	while (p != NULL)
	{
		ptail->next = p;
		tail->next = p->next;
		ptail = ptail->next;
		tail = tail->next;
		p = p->next->next;
	}
	ptail->next = NULL;
	tail->next = NULL;
	return head;
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
