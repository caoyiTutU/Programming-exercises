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
	  ListNode* Merge(ListNode* pHead1, ListNode* pHead2);
  };

  ListNode* Solution::Merge(ListNode* pHead1, ListNode* pHead2)
  {
	  if (pHead1 == NULL)
		  return pHead2;
	  if (pHead2 == NULL)
		  return pHead1;
	  vector<ListNode*> lvec;
	  while (pHead1 != NULL&&pHead2 != NULL)
	  {
		  if (pHead1->val >= pHead2->val)
		  {
			  lvec.push_back(pHead2);
			  pHead2 = pHead2->next;
		  }
		  else
		  {
			  lvec.push_back(pHead1);
			  pHead1 = pHead1->next;
		  }
	  }
	  if (pHead1 == NULL)
	  {
		  while (pHead2 != NULL)
		  {
			  lvec.push_back(pHead2);
			  pHead2 = pHead2->next;
		  }
	  }
	  if (pHead2 == NULL)
	  {
		  while (pHead1 != NULL)
		  {
			  lvec.push_back(pHead1);
			  pHead1 = pHead1->next;
		  }
	  }
	  auto iter = lvec.begin();
	  while (iter != lvec.end()-1)
	  {
		  (*iter)->next = *(iter + 1);
		  ++iter;
	  }
	  (*iter)->next = NULL;
	  return lvec.front();
  }

int main()
{
	Solution sol;
	system("pause");
	return 0;
}