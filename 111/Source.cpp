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
	size_t minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr) return 1;
		if (root->left == nullptr) return 1 + minDepth(root->right);
		if (root->right == nullptr) return 1 + minDepth(root->left);
		auto a = minDepth(root->left);
		auto b = minDepth(root->right);
		return 1 + (a < b ? a : b);
	}
};