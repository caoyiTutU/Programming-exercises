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
#include<bitset>

using namespace std;

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class TreeToSequence {
public:
	vector<vector<int> > convert(TreeNode* root);
private:
	void preorder(TreeNode* root, vector<int> &res);
	void inorder(TreeNode* root, vector<int> &res);
	void postorder(TreeNode* root, vector<int> &res);
};

void TreeToSequence::preorder(TreeNode* root,vector<int> &res)
{
	if (root == NULL)
		return;
	stack<TreeNode*> resStack;
	resStack.push(root);
	while (!resStack.empty())
	{
		TreeNode* curPopNode = resStack.top();
		resStack.pop();
		if (curPopNode->right != NULL)
			resStack.push(curPopNode->right);
		if (curPopNode->left != NULL)
			resStack.push(curPopNode->left);
		res.push_back(curPopNode->val);
	}
}

void TreeToSequence::inorder(TreeNode* root, vector<int> &res)
{
	if (root == NULL)
		return;
	stack<TreeNode*> resStack;
	resStack.push(root);
	TreeNode* curCheckNode = root->left;
	while (!resStack.empty() || curCheckNode != NULL)
	{
		while (curCheckNode != NULL)
		{
			resStack.push(curCheckNode);
			curCheckNode = curCheckNode->left;
		}
		TreeNode *curPopNode = resStack.top();
		resStack.pop();
		res.push_back(curPopNode->val);
		curCheckNode = curPopNode->right;
	}
}

void TreeToSequence::postorder(TreeNode* root, vector<int> &res)
{
	if (root == NULL)
		return;
	stack<TreeNode*> tempStack, resStack;
	tempStack.push(root);
	while (!tempStack.empty())
	{
		TreeNode *curPopNode = tempStack.top();
		tempStack.pop();
		if (curPopNode->left != NULL)
			tempStack.push(curPopNode->left);
		if (curPopNode->right != NULL)
			tempStack.push(curPopNode->right);
		resStack.push(curPopNode);
	}
	while (!resStack.empty())
	{
		res.push_back(resStack.top()->val);
		resStack.pop();
	}
}

vector<vector<int> > TreeToSequence::convert(TreeNode* root)
{
	vector<vector<int>> res;
	if (root == NULL)
		return res;
	vector<int> preoderSequence, inorderSequence, postorderSequence;
	preorder(root, preoderSequence);
	inorder(root, inorderSequence);
	postorder(root, postorderSequence);
	res.push_back(preoderSequence);
	res.push_back(inorderSequence);
	res.push_back(postorderSequence);
	return res;
}

int main()
{
	TreeToSequence tts;
	system("pause");
	return 0;
}
