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
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);
	void rootConstruct(vector<int> p, vector<int> v, TreeNode* r);
};

TreeNode* Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	if (pre.empty() || vin.empty())
		return NULL;
	TreeNode* root = new TreeNode(pre.at(0));
	rootConstruct(pre, vin, root);
	return root;
}

void Solution::rootConstruct(vector<int> p, vector<int> v, TreeNode* r)
{
	unsigned lp = p.size(), lv = v.size();
	if (lp == 1 && lv == 1)
		return;
	else if (lp == 2 && lv == 2)
	{
		TreeNode* child = new TreeNode(p.at(1));
		if (p == v)
			r->right = child;
		else
			r->left = child;
	}
	else
	{
		auto iterv = find(v.begin(), v.end(), p.at(0));
		if (iterv == v.begin())
		{
			TreeNode* rch = new TreeNode(p.at(1));
			r->right = rch;
			vector<int> rchp(p.begin() + 1, p.end());
			vector<int> rchv(iterv + 1, v.end());
			rootConstruct(rchp, rchv, rch);
		}
		else if (iterv == v.end() - 1)
		{
			TreeNode* lch = new TreeNode(p.at(1));
			r->left = lch;
			vector<int> lchp(p.begin() + 1, p.end());
			vector<int> lchv(v.begin(), iterv);
			rootConstruct(lchp, lchv, lch);
		}
		else
		{
			vector<int> lchv(v.begin(), iterv);
			vector<int> rchv(iterv + 1, v.end());
			auto iterp = p.begin() + lchv.size() + 1;
			vector<int> lchp(p.begin() + 1, iterp);
			vector<int> rchp(iterp, p.end());
			TreeNode* lc = new TreeNode(lchp.at(0));
			TreeNode* rc = new TreeNode(rchp.at(0));
			r->left = lc;
			r->right = rc;
			rootConstruct(lchp, lchv, lc);
			rootConstruct(rchp, rchv, rc);
		}
	}
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}