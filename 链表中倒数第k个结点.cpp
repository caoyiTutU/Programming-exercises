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
	  ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
  };

  ListNode* Solution::FindKthToTail(ListNode* pListHead, unsigned int k)
  {
	  if (pListHead == NULL)
		  return NULL;
	  vector<ListNode*> lvec;
	  lvec.push_back(pListHead);
	  while (pListHead->next != NULL)
	  {
		  pListHead = pListHead->next;
		  lvec.push_back(pListHead);
	  }
	  if (k > lvec.size())
		  return NULL;
	  auto iter = lvec.end() - k;
	  return *iter;
  }

int main()
{
	Solution sol;
	system("pause");
	return 0;
}