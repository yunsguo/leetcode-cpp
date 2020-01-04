#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		t_ = target;
		if (nums.size() == 0)
			return { -1,-1 };
		if (nums.size() == 1)
		{
			if (nums.front() == target)
				return{ 0,0 };
			return { -1,-1 };
		}
		if (nums.size() == 2)
		{
			if (nums.front() == target)
				return { 0,nums.back() == target ? 1 : 0 };
			if (nums.back() == target)
				return { 1,1 };
			return { -1,-1 };
		}
		start = 0; end = nums.size() - 1;
		if (nums.front() == target && nums.back() == target) return { 0,(int)nums.size() - 1 };
		if (nums.front() == target) {
			if (nums[1] != target) return { 0,0 };
			search_upper(nums, 0, nums.size() - 1);
		}
		else if (nums.back() == target) {

			if (nums[nums.size() - 2] != target) return { (int)nums.size() - 1,(int)nums.size() - 1 };
			search_lower(nums, 0, nums.size() - 1);
		}
		else
			search_impl(nums, 0, nums.size() - 1);
		return { start,end };
	}

	void search_impl(const vector<int>& nums, size_t lo, size_t hi) {
		auto pivot = (lo + hi) / 2;
		auto p_val = nums[pivot];
		if (p_val == t_)
		{
			if (pivot == 0 || nums[pivot - 1] != t_)
			{
				start = pivot;
				return search_upper(nums, pivot, hi);
			}
			if (pivot == nums.size() - 1 || nums[pivot + 1] != t_)
			{
				end = pivot;
				return search_lower(nums, lo, pivot);
			}
			search_lower(nums, lo, pivot);
			return search_upper(nums, pivot, hi);
		}

		if (hi - lo < 2)
		{
			start = -1;
			end = -1;
			return;
		}

		if (p_val > t_)
			return search_impl(nums, lo, pivot);
		return search_impl(nums, pivot, hi);
	}

	void search_lower(const vector<int>& nums, size_t lo, size_t t_i) {
		auto pivot = (lo + t_i) / 2;
		auto p_val = nums[pivot];
		if (p_val == t_)
		{
			if (pivot == 0 || nums[pivot - 1] != t_)
			{
				start = pivot;
				return;
			}
			return search_lower(nums, lo, pivot);
		}
		return search_lower(nums, pivot, t_i);
	}

	void search_upper(const vector<int>& nums, size_t t_i, size_t hi) {
		auto pivot = (t_i + hi) / 2;
		auto p_val = nums[pivot];
		if (p_val == t_)
		{
			if (pivot == nums.size() - 1 || nums[pivot + 1] != t_)
			{
				end = pivot;
				return;
			}
			return search_upper(nums, pivot, hi);
		}
		return search_upper(nums, t_i, pivot);
	}

private:
	int t_;
	int start;
	int end;
};

void test(vector<int> v, int target)
{
	Solution s;
	cout
		<< "Input: " << v << ", " << target << endl
		<< "Output: " << s.searchRange(v, target) << endl;
}
int main()
{
	test({ 4,5,6,7,0,1,2 }, 0);
	test({ 4,5,6,7,0,1,2 }, 3);
	test({ 1 }, 0);
	test({ 1,3 }, 0);
	test({ 1,3,5 }, 0);
	test({ 3,5,1 }, 5);
	test({ 9,1,2,3,4,5,6,7,8 }, 1);
	test({ 1,2,2 }, 2);
	test({ 1,2,3 }, 3);
	test({ 3,3,3 }, 3);
	test({ 1,2,3,3,3,3,4,5,9 }, 3);
}