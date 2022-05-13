class Solution {
public:
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
	void solve(int col, int n, vector<string>cur, vector<vector<string>>&res) {
		if (col == n) {
			res.push_back(cur);
			return;
		}
		for (int row = 0; row < n; row++) {
			cur[row][col] = 'Q';
			if (isValid(row, col, cur, n)) {
				solve(col + 1, n, cur, res);
			}
			cur[row][col] = '.';
		}
	}
    int totalNQueens(int n) {
        vector<vector<string>>res;
		vector<string>cur;
		string t = "";
		for (int i = 0; i < n; i++) {
			t += '.';
		}
		for (int i = 0; i < n; i++) {
			cur.push_back(t);
		}
		solve(0, n, cur, res);
        return res.size();
    }
};