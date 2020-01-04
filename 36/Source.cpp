#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (size_t i = 0; i < 9; i++)
		{
			if (!check_row(board[i])) return false;
			if (!check_column(board, i)) return false;
			if (!check_subbox(board, i / 3 * 3, i % 3 * 3)) return false;
		}
		return true;
	}

	static bool check_row(vector<char>& row) {
		unordered_set<size_t> list;
		for (auto c : row)
			if (c != '.') {
				size_t temp = c - '0';
				if (list.count(temp) != 0) return false;
				list.insert(temp);
			}
		return true;
	}

	static bool check_column(vector<vector<char>>& board, size_t n) {
		unordered_set<size_t> list;
		for (size_t i = 0; i < 9; i++)
			if (board[i][n] != '.') {
				size_t temp = board[i][n] - '0';
				if (list.count(temp) != 0) return false;
				list.insert(temp);
			}
		return true;
	}

	static bool check_subbox(vector<vector<char>>& board, size_t i, size_t j) {
		unordered_set<size_t> list;
		for (size_t x = 0; x < 3; x++)
			for (size_t y = 0; y < 3; y++)
				if (board[i + x][j + y] != '.') {
					size_t temp = board[i + x][j + y] - '0';
					if (list.count(temp) != 0) return false;
					list.insert(temp);
				}
		return true;
	}
};

void test(vector<vector<char>> v)
{
	Solution s;
	cout
		<< "Input: " << v << endl
		<< "Output: " << (s.isValidSudoku(v) ? "true" : "false") << endl;
}
int main()
{
	test({
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
		});

	test({  {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'5', '.', '.', '.', '.', '.', '.', '9', '.'},
			{'.', '.', '.', '5', '6', '.', '.', '.', '.'},
			{'4', '.', '3', '.', '.', '.', '.', '.', '1'},
			{'.', '.', '.', '7', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '5', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.'} });
}