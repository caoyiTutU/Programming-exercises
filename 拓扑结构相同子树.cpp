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
#include<math.h>
#include<stack>
#include<iomanip>
#include<random>
#include<bitset>
#include<regex>
#include<unordered_set>
#include<memory>

using namespace std;

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class IdenticalTree {
public:
	bool chkIdentical(TreeNode* A, TreeNode* B);
private:
	string serialize(TreeNode* node);
	bool nextarray(const string &str, vector<int> &ivec);
};

bool IdenticalTree::chkIdentical(TreeNode* A, TreeNode* B)
{
	if (A == NULL || B == NULL)
		return false;
	string strA = serialize(A), strB = serialize(B);
	vector<int> ivec;
	if (!nextarray(strB, ivec))
		return false;
	int index = strA.find(strB[0]);
	while (index != string::npos&&index < strA.size())
	{
		int j = index, count = 0;
		for (int i = 0;i < strB.size();++i)
		{
			if (strA[j++] == strB[i])
				++count;
			else
				break;
		}
		if (count == strB.size())
			return true;
		else
			index += count - ivec[count];
	}
	return false;
}

string IdenticalTree::serialize(TreeNode* node)
{
	if (node == NULL)
		return "#,";
	string str, lhs_str = serialize(node->left), rhs_str = serialize(node->right);
	str += to_string(node->val) + "," + lhs_str + rhs_str;
	return str;
}

bool IdenticalTree::nextarray(const string &str, vector<int> &ivec)
{
	int len = str.size(), L = 0;
	ivec.push_back(-1);
	ivec.push_back(0);
	for (int i = 2;i < len;++i)
	{
		while (L > 0 && str[L] != str[i - 1])
			L = ivec[L];
		if (str[L] == str[i - 1])
			++L;
		ivec.push_back(L);
	}
	if (ivec.size() == len)
		return true;
	else
		return false;
}

int main()
{
	IdenticalTree iden;
 	system("pause");
	return 0;
}
