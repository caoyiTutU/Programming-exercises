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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber);
	void storepath(TreeNode* t, vector<int> ivec, int sum);
private:
	vector<vector<int>> vvec;
};

vector<vector<int> > Solution::FindPath(TreeNode* root, int expectNumber)
{
	vector<int> v;
	storepath(root, v, expectNumber);
	return vvec;
}

void Solution::storepath(TreeNode* t, vector<int> ivec,int sum)
{
	if (t == NULL)
		return;
	ivec.push_back(t->val);
	if (t->left == NULL&&t->right == NULL)
	{
		if (accumulate(ivec.begin(), ivec.end(), 0) == sum)
			vvec.push_back(ivec);
	}
	else
	{
		storepath(t->left, ivec, sum);
		storepath(t->right, ivec, sum);
	}
}

int main()
{
	Solution sol;
	system("pause");
	return 0;
}
