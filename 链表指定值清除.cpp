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

class ClearValue {
public:
	ListNode* clear(ListNode* head, int val);
};

ListNode* ClearValue::clear(ListNode* head, int val)
{
	ListNode *p = head, *reshead = NULL, *restail = NULL;
	while (p != NULL)
	{
		if (p->val != val)
		{
			if (restail == NULL)
			{
				reshead = p;
				restail = p;
			}
			else
			{
				restail->next = p;
				restail = p;
			}
		}
		p = p->next;
	}
	restail->next = NULL;
	return reshead;
}

int main()
{
	ClearValue cv;
	system("pause");
	return 0;
}
