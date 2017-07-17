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
	/*ListNode* noLoopInter(ListNode* head1, ListNode* head2, ListNode* end);*/                        //查找环入口前第一个相交的节点
};

bool ChkIntersection::chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1)
{
	ListNode *loopExtrance1 = chkLoop(head1, adjust0), *loopExtrance2 = chkLoop(head2, adjust1);
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

//ListNode* ChkIntersection::noLoopInter(ListNode* head1, ListNode* head2, ListNode* end)
//{
//	ListNode *node1 = head1, *node2 = head2;
//	int len_1 = 0, len_2 = 0;
//	while (node1 != end)
//	{
//		++len_1;
//		node1 = node1->next;
//	}
//	while (node2 != end)
//	{
//		++len_2;
//		node2 = node2->next;
//	}
//	node1 = head1;
//	node2 = head2;
//	if (len_1 < len_2)
//		for (int i = 0;i < len_2 - len_1;++i)
//			node2 = node2->next;
//	else
//		for (int i = 0;i < len_1 - len_2;++i)
//			node1 = node1->next;
//	while (node1 != end&&node2 != end)
//	{
//		if (node1 == node2)
//			return node1;
//		node1 = node1->next;
//		node2 = node2->next;
//	}
//	return NULL;
//}