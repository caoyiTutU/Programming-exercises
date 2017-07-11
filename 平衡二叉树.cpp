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
	bool IsBalanced_Solution(TreeNode* pRoot);
	void treedepth(TreeNode* t, int dep, set<int>& iset);
};

bool Solution::IsBalanced_Solution(TreeNode* pRoot)
{
	if (pRoot == NULL || (pRoot->left == NULL&&pRoot->right == NULL))
		return true;
	set<int> lset, rset;
	treedepth(pRoot->left, 1, lset);
	treedepth(pRoot->right, 1, rset);
	if (abs(*--lset.end() - *--rset.end()) > 1)
		return false;
	else
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}

void Solution::treedepth(TreeNode* t, int dep, set<int>& iset)
{
	if (t == NULL)
	{
		if (dep == 1)
			iset.insert(0);
		return;
	}
	else if (t->left == NULL && t->right == NULL)
		iset.insert(dep);
	else 
	{
		treedepth(t->left, dep + 1, iset);
		treedepth(t->right, dep + 1, iset);
	}
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
