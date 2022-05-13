class Solution {
public:
	bool isValid(int r, int c, char ch, vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[r][j] == ch || board[i][c] == ch || board[3 * (r / 3) + i / 3][3 * (c / 3) + j / 3] == ch) {
					return false;
				}
			}
		}
		return true;
	}
	bool solve(vector<vector<char>>& board) {
		for (int r = 0; r < 9; r++) {
			for (int c = 0; c < 9; c++) {
				if (board[r][c] == '.') {
					for (char ch = '1'; ch <= '9'; ch++) {
						if (isValid(r, c, ch, board)) {
							board[r][c] = ch;
							if (solve(board)) {
								return true;
							}
							else {
								board[r][c] = '.';
							}
						}
					}
					return false;
				}
			}
		}
		return true;
	}
	void solveSudoku(vector<vector<char>>& board) {
		bool ans = solve(board);
	}
};