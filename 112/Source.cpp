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
	bool hasPathSum(TreeNode* root, size_t sum) {
		if (root == nullptr) return false;
		sum -= root->val;
		if (sum == 0 && root->left==nullptr && root->right==nullptr) return true;
		return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
	}
};