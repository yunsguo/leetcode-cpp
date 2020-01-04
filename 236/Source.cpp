#include <iostream>
#include "../leetcode_misc/listcode_misc.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using namespace std;

using TreeNode = TreeNodeOf<int>;

class Solution {

	static bool is_decedent_of(int a, TreeNode* b)
	{
		if (b == nullptr) return false;
		if (b->val == a) return true;
		return is_decedent_of(a, b->left) || is_decedent_of(a, b->right);
	}

	static int lca_search(TreeNode* node, int p, int q, TreeNode*& result)
	{
		if (node == nullptr) return 0;
		if (node->val == p) return 2;
		if (node->val == q) return 3;
		auto response = lca_search(node->left, p, q, result);
		if (response == 1) return 1;
		if (response == 2)
		{
			if (is_decedent_of(q, node->right))
			{
				result = node;
				return 1;
			}
			return 2;
		}
		if (response == 3)
		{
			if (is_decedent_of(p, node->right))
			{
				result = node;
				return 1;
			}
			return 3;
		}
		return lca_search(node->right, p, q, result);
	}
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (is_decedent_of(p->val, q)) return q;
		if (is_decedent_of(q->val, p)) return p;
		TreeNode* result;
		lca_search(root, p->val, q->val, result);
		return result;
	}
};

int main()
{
	TreeNode root(1);
	root.left = new TreeNode(2);
	root.right = new TreeNode(3);
	Solution s;
	cout << "Output: " << s.lowestCommonAncestor(&root, root.right, root.left)->val << endl;
}