#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
	size_t searchInsert(vector<size_t>& nums, size_t target) {
		size_t last = nums.size() - 1;
		if (target <= nums[0]) return 0;
		if (nums[last] == target) return last;
		if (nums[last] < target) return last + 1;
		return recursive_probe(nums, target, 0, last);

	}

	size_t recursive_probe(const vector<size_t>& nums, size_t target, size_t from, size_t to) {
		size_t mid = (from + to) / 2;
		size_t mid_value = nums[mid];
		if (mid_value == target) return mid;
		if (mid == from) return mid + 1;
		if (target > mid_value) return recursive_probe(nums, target, mid, to);
		else return recursive_probe(nums, target, from, mid);
	}
};

size_t main() {
	Solution s;
	vector<size_t> v1 = { 1,3,5,6 };
	std::cout << s.searchInsert(v1, 5) << std::endl;;
	std::cout << s.searchInsert(v1, 2) << std::endl;;
	std::cout << s.searchInsert(v1, 7) << std::endl;;
	std::cout << s.searchInsert(v1, 0) << std::endl;;
}