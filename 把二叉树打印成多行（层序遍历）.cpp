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
	vector<vector<int> > Print(TreeNode* pRoot);
};

vector<vector<int> > Solution::Print(TreeNode* pRoot)
{
	vector<vector<int>> vvec;
	if (pRoot == NULL)
		return vvec;
	TreeNode *last, *nlast;
	deque<TreeNode*> tdeq;
	tdeq.push_back(pRoot);
	last = pRoot;
	vector<int> ivec;
	while (!tdeq.empty())
	{
		ivec.push_back(tdeq.front()->val);
		if (tdeq.front()->left != NULL)
		{
			tdeq.push_back(tdeq.front()->left);
			nlast = tdeq.front()->left;
		}
		if (tdeq.front()->right != NULL)
		{
			tdeq.push_back(tdeq.front()->right);
			nlast = tdeq.front()->right;
		}
		if (tdeq.front() == last)
		{
			vvec.push_back(ivec);
			ivec.clear();
			last = nlast;
		}
		tdeq.pop_front();
	}
	return vvec;
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
