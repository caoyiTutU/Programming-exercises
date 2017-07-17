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

class Common {
public:
	vector<int> findCommonParts(ListNode* headA, ListNode* headB);
};

vector<int> Common::findCommonParts(ListNode* headA, ListNode* headB)
{
	vector<int> res;
	if (headA == NULL || headB == NULL)
		return res;
	ListNode *pa = headA, *pb = headB;
	while (pa != NULL&&pb != NULL)
	{
		if (pa->val > pb->val)
			pb = pb->next;
		else if (pa->val < pb->val)
			pa = pa->next;
		else
		{
			res.push_back(pa->val);
			pa = pa->next;
			pb = pb->next;
		}
	}
	return res;
}

int main()
{
	Common cm;
	system("pause");
	return 0;
}
