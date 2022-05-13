class Solution {
public:
	void solve(int col, int n, vector<string>&cur, vector<vector<string>>&res, vector<int>&LR, vector<int>&LD, vector<int>&UD) {
		if (col == n) {
			res.push_back(cur);
			return;
		}
		for (int row = 0; row < n; row++) {
			if (LR[row] == 0 && LD[row + col] == 0 && UD[n - 1 + col - row] == 0) {
				cur[row][col] = 'Q';
				LR[row] = 1 ,LD[row + col] = 1 ,UD[n - 1 + col - row] = 1;
				solve(col + 1, n, cur, res, LR, LD, UD);
				LR[row] = 0 ,LD[row + col] = 0 ,UD[n - 1 + col - row] = 0;
				cur[row][col] = '.';
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>>res;
		string t = string(n, '.');
		vector<string>cur(n, t);
		vector<int>LR(n, 0), LD(2 * n, 0), UD(2 * n, 0);
		solve(0, n, cur, res, LR, LD, UD);
		return res;
	}
};