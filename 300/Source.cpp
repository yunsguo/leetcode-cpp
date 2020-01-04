#include <vector>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution 
{
public:
	int lengthOfLIS(vector<int>& nums) 
	{
		auto n = nums.size();
		if (n == 0) return 0;
		vector<int> lis(n,1);
		int global_max = 1;
		for (size_t i = 0; i < n; i++)
		{
			int max = 1;
			for (size_t j = 0; j < i; j++)
				if (nums[i] > nums[j])
				{
					auto temp = lis[j] + 1;
					if (temp > max)
						max = temp;
				}
			lis[i] = max;
			if (max > global_max) global_max = max;
		}
		return global_max;
	}
};

void test(vector<int> nums)
{
	cout << "Input: " << nums << endl;
	Solution s;
	cout << "Output: " << s.lengthOfLIS(nums) << endl;
}

int main()
{
	test({ 10,9,2,5,3,7,101,18 });
}