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
	res.push_back(root->val);
	preorder(root->left, res);
	preorder(root->right, res);
}

void TreeToSequence::inorder(TreeNode* root, vector<int> &res)
{
	if (root == NULL)
		return;
	inorder(root->left, res);
	res.push_back(root->val);
	inorder(root->right, res);
}

void TreeToSequence::postorder(TreeNode* root, vector<int> &res)
{
	if (root == NULL)
		return;
	postorder(root->left, res);
	postorder(root->right, res);
	res.push_back(root->val);
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
