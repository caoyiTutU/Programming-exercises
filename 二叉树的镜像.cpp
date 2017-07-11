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
	void Mirror(TreeNode *pRoot);
};

void Solution::Mirror(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return;
	swap(pRoot->left, pRoot->right);
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}


int main()
{
	Solution sol;
	system("pause");
	return 0;
}
