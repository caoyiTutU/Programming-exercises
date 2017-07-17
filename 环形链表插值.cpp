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
#include<math.h>
#include<stack>
#include<iomanip>
#include<random>
#include<bitset>
#include<regex>
#include<unordered_set>
#include<unordered_map>
#include<memory>

using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
class InsertValue {
public:
	ListNode* insert(vector<int> A, vector<int> nxt, int val);
};

ListNode* InsertValue::insert(vector<int> A, vector<int> nxt, int val)
{
	ListNode *node = new ListNode(val);
	if (A.empty())
	{
		node->next = node;
		return node;
	}
	vector<ListNode*> lvec;
	int minindex = 0, maxindex = 0;
	for (int i = 0;i < A.size();++i)
	{
		ListNode* p = new ListNode(A[i]);
		lvec.push_back(p);
		minindex = A[i] < A[minindex] ? i : minindex;
		maxindex = A[i] >= A[maxindex] ? i : maxindex;
	}
	for (int j = 0;j < nxt.size();++j)
		lvec[j]->next = lvec[nxt[j]];
	ListNode *head = lvec[minindex], *pre = head, *cur = pre->next;
	while (pre->val > node->val || node->val > cur->val)
	{
		if (cur == head)
			break;
		pre = pre->next;
		cur = cur->next;
	}
	node->next = cur;
	pre->next = node;
	if (cur != head)
	{
		lvec[maxindex]->next = NULL;
		return head;
	}
	else
	{
		if (val < pre->val)
		{
			pre->next = NULL;
			return node;
		}
		else
		{
			node->next = NULL;
			return head;
		}
	}
}

int main()
{
	vector<int> A = { 4,8,9 }, nxt = { 1,2,0 };
	InsertValue iv;
	ListNode *res = iv.insert(A, nxt, 4);
	system("pause");
	return 0;
}
