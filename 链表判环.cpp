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

class ChkLoop {
public:
	int chkLoop(ListNode* head, int adjust);
};

int ChkLoop::chkLoop(ListNode* head, int adjust)
{
	ListNode *pfast = head, *pslow = head;
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
		return pfast->val;
	}
	else
		return -1;
}


int main()
{
	ChkLoop cl;
	system("pause");
	return 0;
}