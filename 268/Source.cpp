#include <vector>

using namespace std;

class Solution
{
public:
	int missingNumber(vector<int>& nums)
	{
		int max = nums.size();
		int e = 0;
		for (int i = 0; i <= max; i++)
			e = e ^ i;
		for (auto n : nums)
			e = e ^ n;
		return e;
	}
};