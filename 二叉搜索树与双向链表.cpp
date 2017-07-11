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
	TreeNode* Convert(TreeNode* pRootOfTree);
	void inorder(TreeNode* t);
private:
	vector<TreeNode*> tvec;
};

TreeNode* Solution::Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL)
		return NULL;
	tvec.push_back(pRootOfTree);
	inorder(pRootOfTree);
	TreeNode* head = tvec.front(), *r = head;
	r->left = NULL;
	for (auto iter1 = tvec.begin() + 1;iter1 != tvec.end();++iter1)
	{
		r->right = *iter1;
		(*iter1)->left = r;
		r = r->right;
	}
	r->right = NULL;
	return head;
}

void Solution::inorder(TreeNode* t)
{
	if (t->left == NULL && t->right == NULL)
		return;
	auto iter = find(tvec.begin(), tvec.end(), t);
	if (t->left != NULL&&t->right != NULL)
	{
		iter = tvec.insert(iter, t->left);
		tvec.insert(iter + 2, t->right);
		inorder(t->left);
		inorder(t->right);
	}
	else if (t->left == NULL&&t->right != NULL)
	{
		tvec.insert(iter + 1, t->right);
		inorder(t->right);
	}
	else
	{
		tvec.insert(iter, t->left);
		inorder(t->left);
	}
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
