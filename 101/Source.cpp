
struct TreeNode
{
	size_t val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(size_t x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		return mirror_path(root->left, root->right);
	}

	bool mirror_path(TreeNode* p, TreeNode* q)
	{
		if (p == nullptr && q == nullptr) return true;
		if (p != nullptr && q != nullptr)
		{
			if (p->val != q->val) return false;
			return mirror_path(p->left, q->right) && mirror_path(p->right, q->left);
		}
		return false;
	}
};