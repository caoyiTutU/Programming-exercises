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

class CheckIntersect {
public:
	bool chkIntersect(ListNode* headA, ListNode* headB);
};

bool CheckIntersect::chkIntersect(ListNode* headA, ListNode* headB)
{
	if (headA == NULL || headB == NULL)
		return false;
	ListNode *nodeA = headA, *nodeB = headB;
	int len_a = 0, len_b = 0;
	while (nodeA != NULL)
	{
		++len_a;
		nodeA = nodeA->next;
	}
	while (nodeB != NULL)
	{
		++len_b;
		nodeB = nodeB->next;
	}
	nodeA = headA;
	nodeB = headB;
	if (len_a < len_b)
		for (int i = 0;i < len_b - len_a;++i)
			nodeB = nodeB->next;
	else
		for (int i = 0;i < len_a - len_b;++i)
			nodeA = nodeA->next;
	while (nodeA != NULL&&nodeB != NULL)
	{
		if (nodeA == nodeB)
			return true;
		nodeA = nodeA->next;
		nodeB = nodeB->next;
	}
	return false;
}

int main()
{
	CheckIntersect ci;
	system("pause");
	return 0;
}