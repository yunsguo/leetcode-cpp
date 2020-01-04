#include <vector>

using std::vector;

struct TreeNode
{
	size_t val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(size_t x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		auto a = maxDepth(root->left);
		auto d = a - maxDepth(root->right);
		if (d > 1 || d < -1) return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}

	size_t maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		auto a = maxDepth(root->left);
		auto b = maxDepth(root->right);
		return 1 + (a > b ? a : b);
	}
};