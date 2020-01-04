#include <vector>

using namespace std;

class Solution
{
public:
	int findPeakElement(vector<int>& nums)
	{
		if (nums.size() == 1) return 0;
		if (nums.size() <= 2)
		{
			if (nums[0] > nums[1]) return 0;
			if (nums[1] > nums[0]) return 1;
			return -1;
		}
		if (nums[0] > nums[1]) return 0;
		for (size_t i = 1; i < nums.size() - 1; i++)
			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
		if (nums.back() > nums[nums.size() - 2]) return nums.size()-1;
		return -1;
	}
};