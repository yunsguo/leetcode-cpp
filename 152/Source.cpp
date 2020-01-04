#include <vector>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;
//
//class Solution
//{
//public:
//	int maxProduct(vector<int>& nums)
//	{
//		int max = INT32_MIN;
//		vector<int> candidates;
//		candidates.push_back(1);
//		for (auto n : nums)
//		{
//			if (n != 0)
//			{
//				for (auto &c : candidates)
//				{
//					c *= n;
//					if (c > max) max = c;
//				}
//				if (n < 0) candidates.push_back(1);
//				cout << "candidates: " << candidates << endl;
//			}
//			else
//			{
//				candidates.clear();
//				candidates.push_back(1);
//				if (0 > max) max = 0;
//			}
//		}
//		return max;
//	}
//};


class Solution
{
	static void trim(vector<int>& nums)
	{
		if (nums.size() < 2) return;
		int min = INT32_MAX;
		int max = INT32_MIN;
		for (auto n : nums)
		{
			if (n < min)min = n;
			if (n > max)max = n;
		}
		nums.clear();
		nums.push_back(max);
		if (min != max);
		nums.push_back(min);
	}

public:
	int maxProduct(vector<int>& nums)
	{
		int max = INT32_MIN;
		vector<int> candidates;
		candidates.push_back(1);
		for (auto n : nums)
		{
			if (n != 0)
			{
				for (auto &c : candidates)
				{
					c *= n;
					if (c > max) max = c;
				}
				trim(candidates);
				if (n < 0) candidates.push_back(1);
				cout << "candidates: " << candidates << endl;
			}
			else
			{
				candidates.clear();
				candidates.push_back(1);
				if (0 > max) max = 0;
			}
		}
		return max;
	}
};

void test(vector<int> nums)
{
	Solution s;
	cout
		<< "Input: " << nums << endl
		<< "Output: " << s.maxProduct(nums) << endl;
}

int main()
{
	test({ 2,3,-2,4 });
	test({ -2, 0, -1 });
	test({ 3, -1, 4 });
	test({ 2, -5, -2, -4, 3 });
}

