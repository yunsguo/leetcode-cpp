
struct TreeNode
{
	size_t val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(size_t x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	size_t maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		auto a = maxDepth(root->left);
		auto b = maxDepth(root->right);
		return 1 + (a > b ? a : b);
	}
};