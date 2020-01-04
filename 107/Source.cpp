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
	vector<vector<size_t>> levelOrderBottom(TreeNode* root) {
		if (root == nullptr) return {};
		auto d = maxDepth(root);
		vector<vector<size_t>> c(d);
		recursive_fill(c, root,d-1);
		c.back()={ root->val };
		return c;
	}

	size_t maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		auto a = maxDepth(root->left);
		auto b = maxDepth(root->right);
		return 1 + (a > b ? a : b);
	}

	void recursive_fill(vector<vector<size_t>>& c, TreeNode* n,size_t d)
	{
		if (n == nullptr) return;
		c[d].push_back(n->val);
		recursive_fill(c, n->left, d - 1);
		recursive_fill(c, n->right, d - 1);
	}
};