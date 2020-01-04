#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		vector<int> r;
		auto m = matrix.size();
		if (m == 0) return r;
		auto n = matrix.front().size();
		if (m == 1 && n == 1)
		{
			r.push_back(matrix[0][0]);
			return r;
		}
		if (m == 1)
			return matrix[0];
		if (n == 1)
		{
			for (size_t i = 0; i < m; i++)
				r.push_back(matrix[i][0]);
			return r;
		}
		visit(matrix, 0, 0, matrix.size(), matrix.front().size(), r);
		return r;
	}

private:
	static void visit(vector<vector<int>>& matrix, size_t i, size_t j, size_t m, size_t n, vector<int>& container)
	{
		if (m == 1 && n == 1)
		{
			container.push_back(matrix[i][j]);
			return;
		}
		if (m == 1)
		{
			for (size_t k = 0; k < n; k++)
				container.push_back(matrix[i][j + k]);
			return;
		}
		if (n == 1)
		{
			for (size_t k = 0; k < m; k++)
				container.push_back(matrix[i + k][j]);
			return;
		}
		for (size_t k = 0; k < n - 1; k++)
			container.push_back(matrix[i][j + k]);
		auto j2 = j + n - 1;
		for (size_t k = 0; k < m - 1; k++)
			container.push_back(matrix[i + k][j2]);
		auto i2 = i + m - 1;
		for (size_t k = 0; k < n - 1; k++)
			container.push_back(matrix[i2][j2 - k]);
		for (size_t k = 0; k < m - 1; k++)
			container.push_back(matrix[i2 - k][j]);
		if (m*n - 2 * n - 2 * m + 4 == 0) return;
		return visit(matrix, i + 1, j + 1, m - 2, n - 2, container);
	}
};

void test(vector<vector<int>> matrix)
{
	Solution so;
	cout << "Input: " << matrix << endl;
	cout << "Output: " << so.spiralOrder(matrix) << endl << endl;
}

int main()
{
	test({ {3},{2} });
	test({ {1,2},{3,4} });
	test({ {1,2,3},{4,5,6},{7,8,9} });
	test({ {1, 2, 3, 4},{5, 6, 7, 8},{9,10,11,12} });
	test({ {2, 3, 4},{5, 6, 7},{8,9,10},{11,12,13 } });
}