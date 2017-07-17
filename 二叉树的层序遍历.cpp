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

class TreePrinter {
public:
	vector<vector<int> > printTree(TreeNode* root);
};

vector<vector<int> > TreePrinter::printTree(TreeNode* root)
{
	vector<vector<int>> vvec;
	if (root == NULL)
		return vvec;
	deque<TreeNode*> tdeq;
	TreeNode *last = root, *nlast;
	tdeq.push_back(root);
	vector<int> ivec;
	while (!tdeq.empty())
	{
		TreeNode* node = tdeq.front();
		tdeq.pop_front();
		ivec.push_back(node->val);
		if (node->left != NULL)
		{
			nlast = node->left;
			tdeq.push_back(nlast);
		}
		if (node->right != NULL)
		{
			nlast = node->right;
			tdeq.push_back(nlast);
		}
		if (node == last)
		{
			last = nlast;
			vvec.push_back(ivec);
			ivec.clear();
		}
	}
	return vvec;
}

int main()
{
	TreePrinter tree;
	system("pause");
	return 0;
}
