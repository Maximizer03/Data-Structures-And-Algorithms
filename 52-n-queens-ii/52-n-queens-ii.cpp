class Solution {
public:
	int cnt;
	bool isValid(int row, int col, vector<string>&cur, int n) {
		int r = row - 1, c = col - 1;
		while (r >= 0 && c >= 0) {
			if (cur[r][c] == 'Q') {
				return false;
			}
			r--; c--;
		}
		r = row, c = col - 1;
		while (r >= 0 && c >= 0) {
			if (cur[r][c] == 'Q') {
				return false;
			}
			c--;
		}
		r = row + 1, c = col - 1;
		while (r >= 0 && r < n && c >= 0) {
			if (cur[r][c] == 'Q') {
				return false;
			}
			r++; c--;
		}
		return true;
	}
	void solve(int col, int n, vector<string>&cur) {
		if (col == n) {
			cnt++;
			return;
		}
		for (int row = 0; row < n; row++) {
			if (isValid(row, col, cur, n)) {
				cur[row][col] = 'Q';
				solve(col + 1, n, cur);
				cur[row][col] = '.';
			}
		}
	}
	int totalNQueens(int n) {
		vector<vector<string>>res;
		cnt = 0;
		string t = string(n, '.');
		vector<string>cur(n, t);
		solve(0, n, cur);
		return cnt;
	}
};