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
#include<math.h>

using namespace std;

  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head);
};

vector<int> Solution::printListFromTailToHead(ListNode* head)
{
	vector<int> ivec;
	if (head == NULL)
		return ivec;
	ListNode *p = head;
	ivec.push_back(p->val);
	while (p->next != NULL)
	{
		p = p->next;
		ivec.push_back(p->val);
	}
	reverse(ivec.begin(), ivec.end());
	return ivec;
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}