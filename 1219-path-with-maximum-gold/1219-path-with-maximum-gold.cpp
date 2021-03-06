class Solution {
public:
	int ans = 0;
	vector<int>dx, dy;
	int n, m;
	void dfs(int i, int j, vector<vector<int>>&grid, int cost) {
		ans = max(ans, cost);
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k], ny = j + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] > 0) {
				cost += grid[nx][ny];
				grid[nx][ny] *= -1;
				dfs(nx, ny, grid, cost);
				grid[nx][ny] *= -1;
				cost -= grid[nx][ny];
			}
		}
	}
	int getMaximumGold(vector<vector<int>>& grid) {
		n = grid.size(), m = grid[0].size();
		dx = {1, -1, 0, 0};
		dy = {0, 0, 1, -1};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j]) {
					int l = grid[i][j];
					grid[i][j] *= -1;
					dfs(i, j, grid, l);
					grid[i][j] *= -1;
				}
			}
		}
		return ans;
	}
};