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
	  ListNode* ReverseList(ListNode* pHead);
  };

  ListNode* Solution::ReverseList(ListNode* pHead)
  {
	  if (pHead == NULL)
		  return NULL;
	  vector<ListNode*> lvec;
	  lvec.push_back(pHead);
	  while (pHead->next != NULL)
	  {
		  pHead = pHead->next;
		  lvec.push_back(pHead);
	  }
	  auto iter = lvec.rbegin();
	  for (;iter != lvec.rend() - 1;++iter)
		  (*iter)->next = *(iter + 1);
	  (*iter)->next = NULL;
	  return lvec.back();
  }

int main()
{
	Solution sol;
	system("pause");
	return 0;
}