/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <unordered_map>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

using TreeNode = TreeNodeOf<int>;

struct tri_node :public TreeNode
{
	tri_node *up;
	tri_node(int x) : TreeNode(x), up(nullptr) {}
	tri_node(TreeNode node) :TreeNode(node), up(nullptr) {}
};

class Solution
{
	unordered_map<TreeNode*, int> distance_table;

	static void grab_depth(TreeNode* node, int K, vector<int>& result)
	{
		if (node == nullptr) return;
		if (K == 0)
			result.push_back(node->val);
		grab_depth(node->left, K - 1, result);
		grab_depth(node->right, K - 1, result);
	}

	static bool restruct_grab(TreeNode* root, TreeNode* target, vector<int>& result)
	{
		if(root==target)
	}

public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
	{
		if (root == target)
		{
			vector<int> result;
			grab_depth(root, K, result);
			return result;
		}
		distance_table.clear();

	}
};