#include <vector>

using namespace std;

class TicTacToe {
public:
	using byte = unsigned char;

	/** Initialize your data structure here. */
	TicTacToe(int n) :N(n), player1(2 * n + 2, 0), player2(2 * n + 2, 0) {}

	/** Player {player} makes a move at ({row}, {col}).
		@param row The row of the board.
		@param col The column of the board.
		@param player The player, can be either 1 or 2.
		@return The current winning condition, can be either:
				0: No one wins.
				1: Player 1 wins.
				2: Player 2 wins. */
	int move(int row, int col, int player) {
		vector<byte>& currPlayer = player == 1 ? player1 : player2;
		currPlayer[row]++;
		if (currPlayer[row] == N) return player;
		currPlayer[col + N]++;
		if (currPlayer[col + N] == N) return player;
		if (row == col) {
			currPlayer[2 * N]++;
			if (currPlayer[2 * N] == N) return player;
		}
		if (row + col + 1 == N) {
			currPlayer[2 * N + 1]++;
			if (currPlayer[2 * N + 1] == N)return player;
		}
		return 0;
	}
private:
	vector<byte> player1;
	vector<byte> player2;
	int N;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */