#include <vector>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	template<typename T>
	static void three_swap(T& a, T& b, T& c)
	{
		if (b > a)
			swap(a, b);
		if (c > a)
			swap(a, c);
		if (c > b)
			swap(b, c);
	}
	static void quick_sort_just(vector<int>& nums, size_t start, size_t end, size_t k)
	{
		if (start >= end) return;
		if (end - start == 1)
		{
			if (nums[end] > nums[start])
				swap(nums[end], nums[start]);
			return;
		}
		if (end - start == 2)
		{
			three_swap(nums[start], nums[start + 1], nums[end]);
			return;
		}
		auto pi = partition(nums, start, end);
		if (k == pi) return;
		if (k > pi)
			quick_sort_just(nums, pi + 1, end, k);
		else
			quick_sort_just(nums, start, pi - 1, k);
	}

	static size_t partition(vector<int>& nums, size_t start, size_t end)
	{
		auto pivot = nums[start];
		size_t i = end;
		size_t j = start + 1;
		while (j <= end && i >= j)
		{
			if (nums[j] <= pivot)
			{
				swap(nums[i], nums[j]);
				i--;
			}
			else j++;
		}
		j = start;
		while (nums[j] < nums[j+1])
		{
			swap(nums[j], nums[j + 1]);
			j++;
		}
		return j;
	}

	static bool is_ordered(vector<int>& nums)
	{
		for (size_t i = 1; i < nums.size(); i++)
			if (nums[i - 1] < nums[i]) return false;
		return true;
	}

	static bool is_reverse_ordered(vector<int>& nums)
	{
		for (size_t i = 1; i < nums.size(); i++)
			if (nums[i - 1] > nums[i]) return false;
		return true;
	}

public:
	int findKthLargest(vector<int>& nums, int k)
	{
		if (is_ordered(nums)) return nums[k - 1];
		if (is_reverse_ordered(nums)) return nums[nums.size() - k];
		quick_sort_just(nums, 0, nums.size() - 1, k - 1);
		return nums[k - 1];
	}
};

void test(vector<int> nums, int k)
{
	cout << "Input: " << nums << ", " << k << endl;
	Solution s;
	cout << "Output: " << s.findKthLargest(nums, k) << endl;
}

int main()
{
	test({ 3,2,1,5,6,4 }, 2);
	test({ 3, 2, 3, 1, 2, 4, 5, 5, 6 }, 4);
	test({ 7,6,5,4,3,2,1 }, 4);
}