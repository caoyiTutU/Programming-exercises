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

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot);
	bool checklr(TreeNode* lhs, TreeNode* rhs);
};

bool Solution::isSymmetrical(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return true;
	return checklr(pRoot->left, pRoot->right);
}

bool Solution::checklr(TreeNode* lhs, TreeNode* rhs)
{
	if (lhs == NULL&&rhs == NULL)
		return true;
	else if ((lhs == NULL&&rhs != NULL) || ((lhs != NULL) && (rhs == NULL)))
		return false;
	else
	{
		if (lhs->val == rhs->val)
			return checklr(lhs->left, rhs->right) && checklr(lhs->right, rhs->left);
		else
			return false;
	}
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
