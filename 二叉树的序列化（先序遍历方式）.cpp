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

class TreeToString {
public:
	string toString(TreeNode* root);
};

string TreeToString::toString(TreeNode* root)
{
	string res;
	if (root == NULL)
		return res;
	stack<TreeNode*> preOrder;
	preOrder.push(root);
	while (!preOrder.empty())
	{
		TreeNode *curNode = preOrder.top();
		preOrder.pop();
		if (curNode == NULL)
			res += "#!";
		else
		{
			res += to_string(curNode->val) + "!";
			preOrder.push(curNode->right);
			preOrder.push(curNode->left);
		}
	}
	return res;
}

int main()
{
	TreeToString tts;
	system("pause");
	return 0;
}
