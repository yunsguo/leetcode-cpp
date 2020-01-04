#include <vector>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	static bool is_undershoot(const vector<vector<int>>& matrix, size_t index, int target)
	{
		return matrix[index].back() < target;
	}
	static bool is_overshoot(const vector<vector<int>>& matrix, size_t index, int target)
	{
		return matrix[index].front() > target;
	}
	static bool search_row(const vector<vector<int>>& matrix, size_t index, int target)
	{
		auto& row = matrix[index];
		size_t i = 0, j = row.size() - 1;
		if (row[i] == target) return true;
		if (row[j] == target) return true;
		while (true)
		{
			auto mid = (i + j) / 2;
			if (mid == i || mid == j) break;
			if (row[mid] == target) return true;
			if (row[mid] > target) j = mid;
			else i = mid;
		}
		return false;
	}

public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		auto m = matrix.size();
		if (m == 0) return false;
		if (matrix.front().size() == 0) return false;
		for (size_t i = 0; i < m; i++)
		{
			if (is_undershoot(matrix, i, target)) continue;
			if (is_overshoot(matrix, i, target)) break;
			if (search_row(matrix, i, target)) return true;
		}
		return false;
	}
};

void test(vector<vector<int>> matrix, int target)
{
	cout << "Input: target = " << target << ", matrix = " << matrix << endl;
	Solution s;
	cout << "Output: " << (s.searchMatrix(matrix, target) ? "True" : "False") << endl;
}

int main()
{
	vector<vector<int>> target =
	{
	{1,   4,  7, 11, 15},
	{2,   5,  8, 12, 19},
	{3,   6,  9, 16, 22},
	{10, 13, 14, 17, 24},
	{18, 21, 23, 26, 30}
	};
	test(target, 5);
	test(target, 20);
}
