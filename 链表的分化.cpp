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

class Divide {
public:
	ListNode* listDivide(ListNode* head, int val);
private:
	void catnode(ListNode* &head, ListNode* &pre, ListNode* &p);
};

void Divide::catnode(ListNode* &head, ListNode* &pre, ListNode* &p)
{
	if (head == NULL)
	{
		head = p;
		pre = p;
	}
	else
	{
		pre->next = p;
		pre = pre->next;
	}
}

ListNode* Divide::listDivide(ListNode* head, int val)
{
	if (head == NULL)
		return NULL;
	ListNode *minhead = NULL, *maxhead = NULL, *minpre = NULL, *maxpre = NULL, *p = head;
	while (p != NULL)
	{
		if (p->val <= val)
			catnode(minhead, minpre, p);
		else
			catnode(maxhead, maxpre, p);
		p = p->next;
	}
	ListNode *res = NULL, *back = NULL;
	if (minhead != NULL)
	{
		res = minhead;
		back = minpre;
	}
	if (maxhead != NULL)
	{
		if (res == NULL)
		{
			res = maxhead;
			back = maxpre;
		}
		else
		{
			back->next = maxhead;
			back = maxpre;
		}
	}
	back->next = NULL;
	return res;
}

int main()
{
	Divide div;
	system("pause");
	return 0;
}