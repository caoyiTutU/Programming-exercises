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
	map<RandomListNode*, RandomListNode*> rmap;
	RandomListNode *qHead, *r;
	r = new RandomListNode(0);
	r->label = p->label;
	rmap.insert(make_pair(p, r));
	qHead = r;
	while (p->next != NULL)
	{
		RandomListNode *q;
		q = new RandomListNode(0);
		q->label = p->next->label;
		r->next = q;
		rmap.insert(make_pair(p->next, q));
		r = q;
		p = p->next;
	}
	RandomListNode *rdp = pHead, *rdq = qHead;
	while (rdp != NULL&&rdq != NULL)
	{
		rdq->random = rmap[rdp->random];
		rdp = rdp->next;
		rdq = rdq->next;
	}
	return qHead;
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}