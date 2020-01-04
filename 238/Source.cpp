#include <vector>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution 
{
public:
	vector<int> productExceptSelf(vector<int>& nums) 
	{
		auto n = nums.size();
		vector<int> result(n, 1);
		size_t ps = 1;
		for (size_t i = 1; i < n; i++)
		{
			ps *= nums[i-1];
			result[i] *= ps;
		}
		ps = 1;
		for (size_t j = n - 1; j >= 1; j--)
		{
			ps *= nums[j];
			result[j-1] *= ps;
		}
		return result;
	}
};

void test(vector<int> nums)
{
	cout << "Input: " << nums << endl;
	Solution s;
	cout << "Output: " << s.productExceptSelf(nums) << endl;
}

int main()
{
	test({ 1,2,3,4 });
}