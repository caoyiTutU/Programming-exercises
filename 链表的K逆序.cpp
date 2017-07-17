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

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class KInverse {
public:
	ListNode* inverse(ListNode* head, int k);
};

ListNode* KInverse::inverse(ListNode* head, int k)
{
	if (head == NULL || head->next == NULL || k < 2)
		return head;
	vector<ListNode*> lvec;
	ListNode* p = head, *pre = NULL;
	while (p != NULL)
	{
		lvec.push_back(p);
		if (lvec.size() == k)
		{
			lvec[0]->next = lvec[k - 1]->next;
			for (int i = k - 1;i > 0;--i)
				lvec[i]->next = lvec[i - 1];
			if (pre == NULL)
				head = lvec[k - 1];
			else
				pre->next = lvec[k - 1];
			pre = lvec[0];
			p = lvec[0];
			lvec.clear();
		}
		p = p->next;
	}
	return head;
}

int main()
{
	KInverse ki;
	system("pause");
	return 0;
}
