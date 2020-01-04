#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	size_t majorityElement(vector<size_t>& nums) {
		if (nums.size() == 1) return nums[0];
		unordered_map<size_t, size_t> index;
		auto major = nums.size() / 2;
		for (auto n : nums)
		{
			if (index.count(n) == 0) index[n] = 1;
			else
			{
				index[n]++;
				if (index[n] > major)
					return n;
			}
		}
	}
};