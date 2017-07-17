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
#include<bitset>

using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class ChkIntersection {
public:
	bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1);
private:
	ListNode* chkLoop(ListNode* head, int adjust);
	bool loopInter(ListNode* head1, ListNode* head2, ListNode* loopExtrance1, ListNode* loopExtrance2);
	bool noLoopInter(ListNode* head1, ListNode* head2);
};

bool ChkIntersection::chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1)
{
	if (head1 == NULL || head2 == NULL)
		return false;
	ListNode *loopExtrance1 = chkLoop(head1, adjust0), *loopExtrance2 = chkLoop(head2, adjust1);
	if (loopExtrance1 == NULL&&loopExtrance2 == NULL)
		return noLoopInter(head1, head2);
	else if (loopExtrance1 != NULL&&loopExtrance2 != NULL)
		return loopInter(head1, head2, loopExtrance1, loopExtrance2);
	else
		return false;

}

ListNode* ChkIntersection::chkLoop(ListNode* head, int adjust)
{
	ListNode *pfast = head, *pslow = head, *pres = NULL;
	bool isloop = false;
	while (pfast != NULL&&pfast->next != NULL)
	{
		pfast = pfast->next->next;
		pslow = pslow->next;
		if (pfast == pslow)
		{
			isloop = true;
			break;
		}
	}
	if (isloop)
	{
		pfast = head;
		while (pfast != pslow)
		{
			pfast = pfast->next;
			pslow = pslow->next;
		}
		pres = pfast;
	}
	return pres;
}

bool ChkIntersection::loopInter(ListNode* head1, ListNode* head2, ListNode* loopExtrance1, ListNode* loopExtrance2)
{
	if (loopExtrance1 == loopExtrance2)
		return true;
	else
	{
		ListNode* node = loopExtrance1->next;
		while (node != loopExtrance1)
		{
			if (node == loopExtrance2)
				return true;
			node = node->next;
		}
		return false;
	}
}

bool ChkIntersection::noLoopInter(ListNode* head1, ListNode* head2)
{
	ListNode *node1 = head1, *node2 = head2;
	int len_1 = 0, len_2 = 0;
	while (node1 != NULL)
	{
		++len_1;
		node1 = node1->next;
	}
	while (node2 != NULL)
	{
		++len_2;
		node2 = node2->next;
	}
	node1 = head1;
	node2 = head2;
	if (len_1 < len_2)
		for (int i = 0;i < len_2 - len_1;++i)
			node2 = node2->next;
	else
		for (int i = 0;i < len_1 - len_2;++i)
			node1 = node1->next;
	while (node1 != NULL&&node2 != NULL)
	{
		if (node1 == node2)
			return true;
		node1 = node1->next;
		node2 = node2->next;
	}
	return false;
}