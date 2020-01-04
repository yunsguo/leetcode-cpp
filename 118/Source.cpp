#include <vector>
#include <type_traits>

using std::vector;

struct TreeNode
{
	size_t val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(size_t x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<size_t>> generate(size_t numRows) {
		vector<vector<size_t>> result(numRows);
		if (numRows == 0) return result;
		result.front() = { 1 };
		for (size_t i = 1; i < numRows; i++)
			result[i] = next(result[i - 1]);
		return result;
	}

	vector<size_t> next(const vector<size_t>& curr)
	{
		vector<size_t> temp(curr.size() + 1);
		temp.front() = 1;
		for (size_t i = 0; i < curr.size() - 1; i++)
			temp[i + 1] = curr[i] + curr[i + 1];
		temp.back() = 1;
		return temp;
	}
};