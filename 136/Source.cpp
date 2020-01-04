#include <vector>

using std::vector;


class Solution {
public:
	size_t singleNumber(vector<size_t>& nums) {
		size_t i = 0;
		for (auto n : nums)
			i = i ^ n;
		return i;
	}
};