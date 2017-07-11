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
	void storeval(TreeNode* t,int depth);
private:
	map<int, vector<int>> imap;
};

vector<vector<int>> Solution::Print(TreeNode* pRoot)
{
	vector<vector<int>> vvec;
	if (pRoot == NULL)
		return vvec;
	storeval(pRoot, 1);
	for (auto iter = imap.begin();iter != imap.end();++iter)
			vvec.push_back(iter->second);
	return vvec;
}

void Solution::storeval(TreeNode* t,int depth)
{
	if (t == NULL)
		return;
	imap[depth].push_back(t->val);
	storeval(t->left, depth + 1);
	storeval(t->right, depth + 1);
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
