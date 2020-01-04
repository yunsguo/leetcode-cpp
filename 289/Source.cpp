#include <vector>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	static void gof_impl(vector<vector<int>>& board, size_t i, size_t j)
	{
		if (board[i][j] % 10 == 0) return;
		add(board, i - 1, j - 1);
		add(board, i, j - 1);
		add(board, i + 1, j - 1);
		add(board, i - 1, j);
		add(board, i + 1, j);
		add(board, i - 1, j + 1);
		add(board, i, j + 1);
		add(board, i + 1, j + 1);
	}
	static void add(vector<vector<int>>& board, size_t i, size_t j)
	{
		if (i >= board.size()) return;
		if (j >= board[i].size()) return;
		board[i][j] += 10;
	}
	static void normalize(vector<vector<int>>& board, size_t i, size_t j)
	{
		auto neighbor = board[i][j] / 10;
		if (board[i][j] % 10 == 0)
		{
			if (neighbor == 3) board[i][j] = 1;
			else board[i][j] = 0;
		}
		else
		{
			if (neighbor > 3 || neighbor < 2)
				board[i][j] = 0;
			else board[i][j] = 1;
		}
	}
public:
	void gameOfLife(vector<vector<int>>& board)
	{
		size_t m = board.size();
		size_t n = board.front().size();
		for (size_t i = 0; i < m; i++)
			for (size_t j = 0; j < n; j++)
				gof_impl(board, i, j);
		for (size_t i = 0; i < m; i++)
			for (size_t j = 0; j < n; j++)
				normalize(board, i, j);
	}
};

void test(vector<vector<int>> board)
{
	cout << "Input: " << board << endl;
	Solution s;
	s.gameOfLife(board);
	cout << "Output: " << board << endl;
}

int main()
{
	test({
  {0,1,0},
  {0,0,1},
  {1,1,1},
  {0,0,0} 
		});
}