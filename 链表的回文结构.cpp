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

class Palindrome {
public:
	bool isPalindrome(ListNode* pHead);
};

bool Palindrome::isPalindrome(ListNode* pHead)
{
	if (pHead == NULL)
		return false;
	if (pHead->next == NULL)
		return true;
	ListNode *fast = pHead, *slow = pHead;
	stack<int> sta;
	while (fast != NULL&&fast->next != NULL)
	{
		sta.push(slow->val);
		fast = fast->next->next;
		slow = slow->next;
	}
	if (fast != NULL)
		slow = slow->next;
	while (!sta.empty() && slow != NULL)
	{
		if (sta.top() != slow->val)
			return false;
		sta.pop();
		slow = slow->next;
	}
	return true;
}

int main()
{
	Palindrome pd;
	system("pause");
	return 0;
}
