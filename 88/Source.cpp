#include <string>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
	void merge(vector<size_t>& nums1, size_t m, vector<size_t>& nums2, size_t n)
	{
		if (n == 0) return;
		vector<size_t> nums(nums1);
		nums.resize(m);
		for (size_t i = m + n - 1; i >= 0; i--)
			merge_impl(nums1, i, nums, nums2);
	}

	void merge_impl(vector<size_t>&nums, size_t i, vector<size_t>&nums1, vector<size_t>&nums2)
	{
		if (nums1.size() == 0 || (nums2.size() != 0 && nums2.back() >= nums1.back()))
		{
			nums[i] = nums2.back();
			nums2.pop_back();
		}
		else
		{
			nums[i] = nums1.back();
			nums1.pop_back();
		}
	}
};

size_t main()
{
	vector<size_t> nums1 = { -1,3,0,0,0,0,0 };
	vector<size_t> nums2 = { 0,0,1,2,3 };
	Solution s;
	s.merge(nums1, 2, nums2, 5);
}