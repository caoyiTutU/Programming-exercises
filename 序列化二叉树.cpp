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
private:
	TreeNode* decode(char *&str) {
		if (*str == '#') {
			str += 2;
			return NULL;
		}
		int num = 0;
		while (*str != ',')
			num = num * 10 + (*(str++) - '0');
		str++;
		TreeNode *root = new TreeNode(num);
		root->left = decode(str);
		root->right = decode(str);
		return root;
	}
public:
	char* Serialize(TreeNode *root) {
		if (!root) return "#,";
		string r = to_string(root->val);
		r.push_back(',');
		char *left = Serialize(root->left);
		char *right = Serialize(root->right);
		char *ret = new char[strlen(left) + strlen(right) + r.size() + 1];
		strcpy(ret, r.c_str());
		strcat(ret, left);
		strcat(ret, right);
		return ret;
	}
	TreeNode* Deserialize(char *str)
	{
		return decode(str);
	}
};

int main()
{
	Solution sol;
	TreeNode *head = new TreeNode(100);
	TreeNode *lhs = new TreeNode(50), *rhs = new TreeNode(50);
	TreeNode *t = new TreeNode(150);
	head->left = lhs;
	head->right = rhs;
	rhs->left = t;
	cout << sol.Serialize(head);
	system("pause");
	return 0;
}
