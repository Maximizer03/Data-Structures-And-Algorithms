class Solution {
public:
	void dfs(int i, int j, int n, int m, vector<vector<int>>&grid) {
		if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == 0) {
			return;
		}
		grid[i][j] = 0;
		dfs(i + 1, j, n, m, grid);
		dfs(i - 1, j, n, m, grid);
		dfs(i, j + 1, n, m, grid);
		dfs(i, j - 1, n, m, grid);
	}
	int calc(vector<vector<int>>&g) {
		int n = g.size(), m = g[0].size();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] == 1) {
					dfs(i, j, n, m, g);
					cnt++;
				}
			}
		}
		return cnt;
	}
	int minDays(vector<vector<int>>& grid) {
        vector<vector<int>>g = grid;
		int cnt = calc(g);
		int n = grid.size(), m = grid[0].size();
		if (cnt != 1) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					vector<vector<int>>g = grid;
					g[i][j] = 0;
					int cnt = calc(g);
					if (cnt !=1) {
						return 1;
					}
				}
			}
		}
		return 2;
	}
};