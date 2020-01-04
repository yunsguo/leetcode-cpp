/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;
using TreeNode = TreeNodeOf<int>;

class Solution 
{
	static TreeNode* is_impl(TreeNode* curr, TreeNode* p)
	{
		if (curr == p)
		{
			auto right_child = trival_right(curr->right);
			return right_child == nullptr ? p : right_child;
		}
		if (curr == nullptr) return nullptr;
		auto left_result = is_impl(curr->left, p);
		if (left_result == p)
			return curr;
		if (left_result != nullptr) return left_result;
		return is_impl(curr->right, p);
	}
	static TreeNode* trival_right(TreeNode* curr)
	{
		if (curr == nullptr) return nullptr;
		while (curr->left != nullptr)
			curr = curr->left;
		return curr;
	}
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
	{
		auto result = is_impl(root, p);
		if (result == p) return nullptr;
		return result;
	}
};
