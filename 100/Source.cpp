
struct TreeNode 
{
   size_t val;
    TreeNode *left;
   TreeNode *right;
    TreeNode(size_t x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		if (p != nullptr && q != nullptr) 
		{
			if (p->val != q->val) return false;
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		if (p == nullptr && q == nullptr) return true;
		return false;
	}
};

size_t main()
{

}