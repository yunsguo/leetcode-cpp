#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	static bool compare(int a, int b)
	{
		if (significant_figure(a) == significant_figure(b)) return a > b;
		auto a_str = to_string(a);
		auto b_str = to_string(b);
		return stoi(a_str + b_str) > stoi(b_str + a_str);
	}

	static bool check_quick_check(int a, int b)
	{
		if (a > b) return check_quick_check(b, a);
		return try_compare(significant_figure(a), b);
	}

	static size_t significant_figure(int a)
	{
		if (a / 10 == 0) return 1;
		return significant_figure(a / 10) + 1;
	}

	static bool try_compare(size_t n, int b)
	{
		if (n == 1) return b / 10 == 0;
		return try_compare(n - 1, b / 10);
	}

public:

	string largestNumber(vector<int>& nums)
	{
		sort(nums.begin(), nums.end(), Solution::compare);
		if (nums.front() == 0) return "0";
		string result = "";
		for (auto n : nums)
			result += to_string(n);
		return result;
	}
};

void test(vector<int> nums)
{
	cout << "Input: " << nums << endl;
	Solution s;
	cout << "Output: " << s.largestNumber(nums) << endl;
}

int main()
{
	test({ 10,2 });
	test({ 3,30,34,5,9 });
	test({ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 });
	test({ 0,0 });
}