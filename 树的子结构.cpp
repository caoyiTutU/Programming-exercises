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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
	void find(TreeNode* p, int v);
	bool issubstructure(TreeNode* p1, TreeNode* p2);
private:
	vector<TreeNode*> tvec;
};

bool Solution::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL || pRoot2 == NULL)
		return false;
	find(pRoot1, pRoot2->val);
	for (const auto &t : tvec)
	{
		if (issubstructure(t, pRoot2))
			return true;
	}
	return false;
}

void Solution::find(TreeNode* p, int v)
{
	if (p == NULL)
		return;
	if (p->val == v)
		tvec.push_back(p);
	find(p->left, v);
	find(p->right, v);
}

bool Solution::issubstructure(TreeNode* p1, TreeNode* p2)
{
	if (p2 == NULL)
		return true;
	else if (p1 != NULL && p2 != NULL)
	{
		if (p1->val == p2->val)
			return issubstructure(p1->left, p2->left) && issubstructure(p1->right, p2->right);
		else
			return false;
	}
	else
		return false;
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
