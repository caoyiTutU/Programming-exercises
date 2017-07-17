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

class CountNodes {
public:
	int count(TreeNode* root);
private:
	void countSubTree(TreeNode*root, int &sum);
	int searchLeftMostNode(TreeNode* root);
};

int CountNodes::count(TreeNode* root)
{
	if (root == NULL)
		return 0;
	int sum = 0;
	countSubTree(root, sum);
	return sum;
}

void CountNodes::countSubTree(TreeNode* root, int &sum)
{
	int curTreeDepth = searchLeftMostNode(root);
	if (curTreeDepth == 0)
		return;
	else if (curTreeDepth == 1)
	{
		sum += 1;
		return;
	}
	else
	{
		int curRightSubTreeDepeh = searchLeftMostNode(root->right);
		if (curTreeDepth - curRightSubTreeDepeh == 1)
		{
			sum += pow(2, curTreeDepth - 1);
			countSubTree(root->right, sum);
		}
		else
		{
			sum += pow(2, curTreeDepth - 2);
			countSubTree(root->left, sum);
		}
	}
}

int CountNodes::searchLeftMostNode(TreeNode* root)
{
	if (root == NULL)
		return 0;
	int curTreeDepth = 1;
	TreeNode *node = root->left;
	while (node != NULL)
	{
		++curTreeDepth;
		node = node->left;
	}
	return curTreeDepth;
}

int main()
{
	CountNodes cn;
	system("pause");
	return 0;
}
