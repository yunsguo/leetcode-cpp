#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"
#include <unordered_set>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
			move_around(nums, i, i);
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != i + 1) return i + 1;
		return nums.size() + 1;
	}

	void move_around(vector<int>& nums, int i, int loop_case = -1)
	{
		if (nums[i] > nums.size() || nums[i] == i + 1 || nums[i] <= 0)
			return;
		auto place = nums[i] - 1;
		if (nums[place] == i + 1)
		{
			swap(nums[i], nums[place]);
			return;
		}
		nums[i] = -1;
		if (place > loop_case)
			move_around(nums, place, loop_case);
		nums[place] = place + 1;
	}
};

void test(vector<int> v)
{
	Solution s;
	cout << "Input: " << v << endl;
	cout << "Output: " << s.firstMissingPositive(v) << endl << endl;
}

int main()
{
	test({ 1,2,0 });
	test({ 2,1 });
	test({ 4,1,2,3 });
	test({ 10,4,16,54,17,-7,21,15,25,31,61,1,6,12,21,46,16,56,54,12,23,20,38,63,2,27,35,11,13,47,13,11,61,39,0,14,42,8,16,54,50,12,-10,43,11,-1,24,38,-10,13,60,0,44,11,50,33,48,20,31,-4,2,54,-6,51,6 });
}