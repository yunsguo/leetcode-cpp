#include <unordered_map>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

using TreeNode = TreeNodeOf<int>;

class Solution
{
	using SizeMap = unordered_map<TreeNode*, size_t>;
	static size_t size(TreeNode* node, SizeMap& size_map)
	{
		if (node == nullptr) return 0;
		if (size_map.count(node) != 0) return size_map.at(node);
		auto left_size = size(node->left, size_map);
		auto right_size = size(node->right, size_map);
		size_map[node] = 1 + left_size + right_size;
		return size_map.at(node);
	}

	static int retrive_kth(TreeNode* node, size_t k, SizeMap& size_map)
	{
		auto left_size = size(node->left, size_map);
		if (k <= left_size) return retrive_kth(node->left, k, size_map);
		if (k == left_size + 1) return node->val;
		return retrive_kth(node->right, k - left_size - 1, size_map);
	}

public:
	int kthSmallest(TreeNode* root, int k)
	{
		unordered_map<TreeNode*, size_t> size_map;
		return retrive_kth(root, k, size_map);
	}
};

int main()
{
	auto root = new TreeNode(5);
}