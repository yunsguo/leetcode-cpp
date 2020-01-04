#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	size_t rob(vector<size_t>& nums) {
		size = nums.size();
		table = vector<size_t>(nums.size(), -1);
		if (size == 0) return 0;
		if (size == 1) return nums[0];
		auto temp = max(nums[0], nums[1]);
		return max(nums[0] + get_max(nums, 2), nums[1] + get_max(nums, 3));
	}

private:
	size_t get_max(const vector<size_t>& nums, size_t start) {
		if (start >= size) return 0;
		if (table[start] != -1) return table[start];
		if (start == size - 1) { 
			table[start] = nums.back();
			return nums.back(); 
		}
		auto first = nums[start] + get_max(nums, start + 2);
		auto second = nums[start + 1] + get_max(nums, start + 3);
		auto max_ = max(first, second);
		table[start] = max_;
		return max_;
	}
	size_t size;
	vector<size_t> table;
};

size_t main()
{
	vector<size_t> test = { 1,2,3,1 };
	vector<size_t> test2 = { 2,7,9,3,1 };
	Solution s;
	s.rob(test2);
}