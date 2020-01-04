#include <vector>
#include <unordered_set>
#include <stack>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	void traverse(vector<vector<char>>& grid, size_t i)
	{
		if (visited.count(i - cn) == 0 && check_neighbor(grid, i - cn))
			_stack.push(i - cn);
		if (visited.count(i + cn) == 0 && check_neighbor(grid, i + cn))
			_stack.push(i + cn);
		if (i%cn != 0 && visited.count(i - 1) == 0 && check_neighbor(grid, i - 1))
			_stack.push(i - 1);
		if (i%cn != cn - 1 && visited.count(i + 1) == 0 && check_neighbor(grid, i + 1))
			_stack.push(i + 1);
	}

	bool check_neighbor(vector<vector<char>>& grid, size_t i)
	{
		if (i >= rn * cn) return false;
		return grid[i / cn][i%cn] == '1';
	}

	char get(vector<vector<char>>& grid, size_t i)
	{
		return grid[i / cn][i%cn];
	}

	size_t cn;
	size_t rn;
	size_t max;
	unordered_set<size_t> visited;
	stack<size_t> _stack;

public:
	int numIslands(vector<vector<char>>& grid)
	{
		rn = grid.size();
		if (rn == 0) return 0;
		cn = grid.front().size();
		visited.clear();
		_stack = std::stack<size_t>();
		max = 0;
		for (size_t i = 0; i < rn*cn; i++)
		{
			if (visited.count(i) != 0 || get(grid, i) == '0')
				continue;
			max++;
			_stack.push(i);
			while (!_stack.empty())
			{
				auto back = _stack.top();
				_stack.pop();
				if (visited.count(back) != 0)
					continue;
				traverse(grid, back);
				visited.insert(back);
			}
		}
		return max;
	}
};

void test(vector<vector<char>> grid)
{
	Solution s;
	cout << "Input: " << grid << endl;
	cout << "Output: " << s.numIslands(grid) << endl;
}

int main()
{
	test({
		{ '1','1','1','1','0' },
		{ '1','1','0','1','0' },
		{ '1','1','0','0','0' },
		{ '0','0','0','0','0' } });

	test({
		{ '1','1','0','0','0' },
		{ '1','1','0','0','0' },
		{ '0','0','1','0','0' },
		{ '0','0','0','1','1' } });
}