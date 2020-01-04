#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
	size_t maxSubArray(vector<size_t>& nums) {
	size_t curSum = 0, ans = INT_MIN;
	for (size_t i = 0; i < nums.size(); i++) {
		curSum += nums[i];
		ans = curSum > ans ? curSum : ans;
		if (curSum <= 0) {
			curSum = 0;
		}
	}
	return ans;
}

	size_t maxSubArrayTest(vector<size_t>& nums) {
		size_t max = INT32_MIN;
		for (size_t i = 0; i < nums.size(); i++)
			for (size_t j = i; j < nums.size(); j++) {
				size_t sum = 0;
				for (size_t k = i; k <= j; k++)
					sum += nums[k];
				if (sum > max)max = sum;
			}
		return max;
	}
};

size_t main() {
	vector<size_t> t1 = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<size_t> t2 = { -2, 1, -3, -4, -1, -2, -1, -5, -4 };
	vector<size_t> t3 = { 1,2 };
	vector<size_t> t4 = { 0,-3,1,1 };
	Solution s;
	std::cout << s.maxSubArray(t1) << std::endl;
	std::cout << s.maxSubArrayTest(t1) << std::endl;
	std::cout << s.maxSubArray(t2) << std::endl;
	std::cout << s.maxSubArrayTest(t2) << std::endl;
	std::cout << s.maxSubArray(t3) << std::endl;
	std::cout << s.maxSubArrayTest(t3) << std::endl;
	std::cout << s.maxSubArray(t4) << std::endl;
	std::cout << s.maxSubArrayTest(t4) << std::endl;
}