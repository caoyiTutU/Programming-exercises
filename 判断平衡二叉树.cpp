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

class CheckBalance {
public:
	bool check(TreeNode* root);
private:
	pair<bool, int> checkSubTreeAndReturnHeight(TreeNode* node);
};

bool CheckBalance::check(TreeNode *root)
{
	if (root == nullptr)
		return true;
	auto res = checkSubTreeAndReturnHeight(root);
	return res.first;
}

pair<bool, int> CheckBalance::checkSubTreeAndReturnHeight(TreeNode* node)
{
	if (node == nullptr)
		return make_pair(true, 0);
	if (node->left == nullptr&&node->right == nullptr)
		return make_pair(true, 1);
	auto leftSubTreeInfo = checkSubTreeAndReturnHeight(node->left);
	if (!leftSubTreeInfo.first)
		return make_pair(false, 0);
	auto rightSubTreeInfo = checkSubTreeAndReturnHeight(node->right);
	if (!rightSubTreeInfo.first)
		return make_pair(false, 0);
	if (abs(leftSubTreeInfo.second - rightSubTreeInfo.second) > 1)
		return make_pair(false, 0);
	else
		return make_pair(true, max(leftSubTreeInfo.second, rightSubTreeInfo.second) + 1);
}


int main()
{
	CheckBalance cb;
	system("pause");
	return 0;
}
