#include <vector>
#include <string>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	static string element_range(int lower, int elem)
	{
		if (lower >= elem)
			return "";
		return true_range(lower, elem - 1);
	}

	static string true_range(int lower, int upper)
	{
		if (lower > upper) return "";
		if (lower == upper) return to_string(lower);
		return to_string(lower) + "->" + to_string(upper);
	}

	static void fmr_impl(const vector<int>& nums, vector<string>& result, int lower, int upper)
	{

		for (size_t i = 0; i < nums.size() - 1; i++)
		{
			auto n = nums[i];
			string r = element_range(lower, n);
			lower = n + 1;
			if (r != "") result.push_back(r);
		}
		string r = element_range(lower, nums.back());
		if (r != "") result.push_back(r);
		if (nums.back() == upper) return;
		string last = true_range(nums.back() + 1, upper);
		if (last != "")
			result.push_back(last);
	}

public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
	{
		vector<string> result;
		vector<int> unique_nums;
		if (nums.size() == 0)
		{
			result.push_back(true_range(lower, upper));
			return result;
		}
		unique_nums.push_back(nums.front());
		for (size_t i = 1; i < nums.size(); i++)
			if (nums[i] != unique_nums.back())unique_nums.push_back(nums[i]);
		fmr_impl(unique_nums, result, lower, upper);
		return result;
	}
};

void test(vector<int> nums, int lower, int upper)
{
	Solution s;
	cout << "Input: " << nums << ", " << lower << ", " << upper << endl;
	cout << "Output: " << s.findMissingRanges(nums, lower, upper) << endl;
}

int main()
{
	test({ 0,1,3,50,75 }, 0, 99);
	test({ }, 1, 1);
	test({ INT32_MIN,2147483647 }, INT32_MIN, 2147483647);
	test({ INT32_MIN,INT32_MIN,0,2147483647,2147483647 }, INT32_MIN, 2147483647);
}