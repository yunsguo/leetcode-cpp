#include <vector>
#include <algorithm>
#include <iostream>
#include "../util/util.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		auto size = nums.size();
		vector<int> negations(size);
		unordered_map<int, int> set;
		for (int i = 0; i < size; i++) {
			negations[i] = target - nums[i];
			set[nums[i]] = i;
		}

		for (int i = 0; i < size; i++) {
			auto neg = negations[i];
			if (set.count(neg) != 0 && set.at(neg) != i)
				return { i,set.at(negations[i]) };
		}
		return {};
	}
};


int main() {
	Solution s;
	vector<int> v1 = { 2, 7, 11, 15 };
	vector<int> v2 = { 3,2,4 };
	cout << s.twoSum(v1, 9) << endl;
	cout << s.twoSum(v2, 6) << endl;
}