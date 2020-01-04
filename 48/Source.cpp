#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix)
	{
		auto depth = (matrix.size() + 1) / 2;
		n_ = matrix.front().size() - 1;
		for (size_t i = 0; i < depth; i++)
			for (size_t j = i; j < n_ - i; j++)
			{
				auto temp = matrix[i][j];
				recursive_shift(matrix, j, n_ - i, i, j);
				matrix[j][n_ - i] = temp;
			}
	}

	void recursive_shift(vector<vector<int>>& matrix, size_t i, size_t j, size_t initial_i, size_t initial_j)
	{
		if (i == initial_i && j == initial_j) return;
		auto temp = matrix[i][j];
		recursive_shift(matrix, j, n_ - i, initial_i, initial_j);
		matrix[j][n_ - i] = temp;
	}
private:
	size_t n_;
};

void test(vector<vector<int>> nums)
{
	Solution so;
	cout << "Input: " << nums << endl;
	so.rotate(nums);
	cout << "Output: " << nums << endl << endl;
}

int main()
{
	test({ {1,2,3},{4,5,6},{7,8,9} });
	test({ {5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16} });
}