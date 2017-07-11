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
	vector<int> PrintFromTopToBottom(TreeNode* root);
	void treepush(TreeNode* p,int depth);
private:
	map<int, vector<int>> imap;
};

vector<int> Solution::PrintFromTopToBottom(TreeNode* root)
{
	vector<int> ivec;
	treepush(root, 1);
	for (auto iter = imap.begin();iter != imap.end();++iter)
		for (const auto &i : iter->second)
			ivec.push_back(i);
	return ivec;
}

void Solution::treepush(TreeNode* p,int depth)
{
	if (p == NULL)
		return;
	imap[depth].push_back(p->val);
	treepush(p->left, depth + 1);
	treepush(p->right, depth + 1);
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
