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
	TreeNode* KthNode(TreeNode* pRoot, int k);
	vector<TreeNode*> inorder(TreeNode* t);
};

TreeNode* Solution::KthNode(TreeNode* pRoot, int k)
{
	if (pRoot == NULL || k < 1)
		return NULL;
	vector<TreeNode*> tvec = inorder(pRoot);
	if (k > tvec.size())
		return NULL;
	else
		return *(tvec.begin() + k - 1);
}

vector<TreeNode*> Solution::inorder(TreeNode* t)
{
	if (t == NULL)
	{
		vector<TreeNode*> empty;
		return empty;
	}
	vector<TreeNode*> lhs = inorder(t->left), rhs = inorder(t->right);
	lhs.push_back(t);
	lhs.insert(lhs.end(), rhs.begin(), rhs.end());
	return lhs;
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
