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
	int TreeDepth(TreeNode* pRoot);
	void storedepth(TreeNode* t, int dep);
private:
	set<int> iset;
};

int Solution::TreeDepth(TreeNode* pRoot)
{
	int depth = 0;
    if(pRoot == NULL)
        return depth;
	storedepth(pRoot, depth);
	return *--iset.end();
}

void Solution::storedepth(TreeNode* t, int dep)
{
	if (t == NULL)
		return;
	if (t->left == NULL &&t->right == NULL)
		iset.insert(++dep);
	else
	{
		++dep;
		storedepth(t->left, dep);
		storedepth(t->right, dep);
	}
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
