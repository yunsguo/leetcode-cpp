#include <vector>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution 
{
public:
	void moveZeroes(vector<int>& nums) 
	{
		size_t zeros = 0;
		size_t n = nums.size();
		for (size_t i = 0; i < n; i++)
		{
			if (nums[i] == 0)
				zeros++;
			else
				nums[i - zeros] = nums[i];
		}
		for (size_t i = 1; i <= zeros; i++)
			nums[n - i] = 0;
	}
};

void test(vector<int> nums)
{
	cout << "Input: " << nums << endl;
	Solution s;
	s.moveZeroes(nums);
	cout << "Output: " << nums << endl;
}

int main()
{
	test({ 0,1,0,3,12 });
}