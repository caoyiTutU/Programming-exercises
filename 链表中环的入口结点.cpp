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
	ListNode* EntryNodeOfLoop(ListNode* pHead);
};

ListNode* Solution::EntryNodeOfLoop(ListNode *pHead)
{
	if (pHead == NULL)
		return NULL;
	set<ListNode*> lset;
	ListNode* p = pHead;
	lset.insert(p);
	while (p->next != NULL)
	{
		auto flag = lset.insert(p->next);
		if (flag.second == false)
			return *flag.first;
		p = p->next;
	}
	return NULL;
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}