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
class Remove {
public:
	bool removeNode(ListNode* pNode);
};

bool Remove::removeNode(ListNode* pNode)
{
	if (pNode->next == NULL)
		return false;
	ListNode *p = pNode->next;
	pNode->val = p->val;
	pNode->next = p->next;
	delete p;
	return true;
}

int main()
{
	Remove rm;
	system("pause");
	return 0;
}
