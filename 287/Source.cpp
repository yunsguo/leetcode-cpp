#include <vector>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
public:
	int findDuplicate(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[abs(nums[i])] >= 0)
				nums[abs(nums[i])] = -nums[abs(nums[i])];
			else
				return abs(nums[i]);
		}
		return 0;
	}
};

void test(vector<int> nums)
{
	cout << "Input: " << nums << endl;
	Solution s;
	cout << "Output: " << s.findDuplicate(nums) << endl;
}

void input_test()
{

}

int main(int argc, char *argv[])
{
	//test({3,1,3,4,2});
}