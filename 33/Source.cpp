#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		if (nums.size() == 1) return nums.front() == target ? 0 : -1;
		auto front = nums.front();
		if (front == target)
			return 0;
		auto back = nums.back();
		if (back == target)
			return nums.size() - 1;
		if (nums.size() == 2) return -1;
		t_i = -1;
		target_ = target;
		size_ = nums.size();
		if (front <= nums[1] && front <= nums.back())
			pivot_ = 0;
		else if (back <= nums[nums.size() - 2] && back <= nums.front())
			pivot_ = nums.size() - 1;
		else
			find_pivot(nums, 0, nums.size() - 1);
		if (t_i != -1) return t_i;
		if (nums[module(0)] == target) return module(0);
		if (nums[module(size_ - 1)] == target) return module(size_ - 1);
		return search_with_pivot(nums, 0, nums.size() - 1);
	}

	int search_with_pivot(vector<int>& nums, size_t lo, size_t hi)
	{
		auto mid = (lo + hi) / 2;
		auto mid_val = nums[module(mid)];
		if (mid_val == target_)
			return module(mid);
		if (hi - lo < 2) return -1;
		if (target_ > mid_val)
			return search_with_pivot(nums, mid, hi);
		return search_with_pivot(nums, lo, mid);
	}

	void find_pivot(const vector<int>& nums, size_t lo, size_t hi)
	{
		auto mid = (lo + hi) / 2;
		auto mid_val = nums[mid];
		if (mid_val == target_) { t_i = mid; return; }
		if (mid_val >= nums[lo])
			return find_pivot(nums, mid, hi);

		if (nums[(mid - 1) % size_] >= mid_val && nums[(mid + 1) % size_] >= mid_val)
		{
			pivot_ = mid;
			return;
		}
		return find_pivot(nums, lo, mid);
	}

	size_t module(size_t i) { return (i + pivot_) % size_; }

private:
	int pivot_;
	size_t p_i;
	int t_i;
	int target_;
	size_t size_;
};

void test(vector<int> v, int target)
{
	Solution s;
	cout
		<< "Input: " << v << ", " << target << endl
		<< "Output: " << s.search(v, target) << endl;
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
}