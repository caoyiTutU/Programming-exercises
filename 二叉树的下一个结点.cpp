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
#include<stack>

using namespace std;

struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode);
};

TreeLinkNode* Solution::GetNext(TreeLinkNode* pNode)
{
	if (pNode->right == NULL)
	{
		TreeLinkNode *par = pNode->next;
		while (par != NULL)
		{
			if (par->left == pNode)
				return par;
			else
			{
				pNode = par;
				par = par->next;
			}
		}
		return NULL;
	}
	else
	{
		TreeLinkNode *p = pNode->right;
		while (p->left != NULL)
			p = p->left;
		return p;
	}
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
