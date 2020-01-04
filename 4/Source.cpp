#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	static double simple_median(vector<int>& nums1, vector<int>& nums2)
	{
		auto size = nums1.size() + nums2.size();
		if (size % 2 == 1)
			return concat_index(nums1, nums2, size / 2);
		return ((double)concat_index(nums1, nums2, size / 2) + concat_index(nums1, nums2, size / 2 - 1)) / 2.0;
	}

	static int concat_index(vector<int>& nums1, vector<int>& nums2, size_t i)
	{
		if (i >= nums1.size()) return nums2[i - nums1.size()];
		return nums1[i];
	}

	static double fmsa_odd_impl(vector<int>& nums1, vector<int>& nums2)
	{

	}

	static double fmsa_even_impl(vector<int>& nums1, vector<int>& nums2)
	{

	}

public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		if (nums1.front() > nums2.front()) return findMedianSortedArrays(nums2, nums1);
		if (nums2.front() >= nums1.back()) return simple_median(nums1, nums2);
		auto size = nums1.size() + nums2.size();
		if (size % 2 == 1) return fmsa_odd_impl(nums1, nums2);
		return fmsa_even_impl(nums1, nums2);
	}
};

void test(vector<int> nums1, vector<int> nums2)
{
	Solution s;
	cout << "Input: " << nums1 << ", " << nums2 << endl;
	cout << "Output: " << s.findMedianSortedArrays(nums1, nums2) << endl;
}

size_t main()
{
	test({ 1,3 }, { 2 });
	test({ 1,2 }, { 3,4 });
}