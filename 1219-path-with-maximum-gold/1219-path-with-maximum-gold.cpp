class Solution {
public:
	int ans = 0;
	vector<int>dx, dy;
	int n, m;
	void dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vis, int cost) {
		ans = max(ans, cost);
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k], ny = j + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] > 0 && vis[nx][ny] == 0) {
				vis[nx][ny] = 1;
				cost += grid[nx][ny];
				dfs(nx, ny, grid, vis, cost);
				cost -= grid[nx][ny];
				vis[nx][ny] = 0;
			}
		}
	}
	int getMaximumGold(vector<vector<int>>& grid) {
		n = grid.size(), m = grid[0].size();
		dx = {1, -1, 0, 0};
		dy = {0, 0, 1, -1};
		vector<vector<int>>vis(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j]) {
					vis[i][j] = 1;
					dfs(i, j, grid, vis, grid[i][j]);
					vis[i][j] = 0;
				}
			}
		}
		return ans;
	}
};