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
	TreeNode * sortedArrayToBST(vector<size_t>& nums) {
		return satb_impl(nums, 0, nums.size());
	}

	TreeNode * satb_impl(vector<size_t>& nums,size_t start,size_t length) {
		if (start >= length) return nullptr;
		auto pivot = (start + length) / 2;
		auto tn = new TreeNode(nums[pivot]);
		tn->left = satb_impl(nums, start, pivot);
		tn->right = satb_impl(nums, pivot + 1, length);
		return tn;
	}

};