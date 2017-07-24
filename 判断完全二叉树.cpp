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

class CheckCompletion {
public:
	bool chk(TreeNode* root);
};

bool CheckCompletion::chk(TreeNode* root)
{
	if (root == nullptr)
		return true;
	queue<TreeNode *> orderQueue;
	orderQueue.push(root);
	bool isLeafNode = false;
	while (!orderQueue.empty())
	{
		TreeNode *curNode = orderQueue.front();
		orderQueue.pop();
		if (isLeafNode)
		{
			if (curNode->left != nullptr || curNode->right != nullptr)
				return false;
		}
		else
		{
			if (curNode->left == nullptr&&curNode->right != nullptr)
				return false;
			else if(curNode->left != nullptr&&curNode->right != nullptr)
			{
				orderQueue.push(curNode->left);
				orderQueue.push(curNode->right);
			}
			else
				isLeafNode = true;
		}
	}
	return true;
}

int main()
{
	CheckCompletion cc;
	system("pause");
	return 0;
}
