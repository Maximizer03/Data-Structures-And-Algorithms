class Solution {
public:
	bool dfs(int v, int p, vector<int>&vis, vector<set<int>>&g) {
		vis[v] = 1;
		for (auto &u : g[v]) {
			if (vis[u] == 0) {
				if (dfs(u, v, vis, g)) {
					return 1;
				}
			}
			else if (u != p) {
				return 1;
			}
		}
		return 0;
	}
	bool containsCycle(vector<vector<char>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<int>dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
		vector<set<int>>g(n * m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (x >= 0 && y >= 0 && x < n && y < m && grid[i][j] == grid[x][y]) {
						int u = i * m + j;
						int v = x * m + y;
						g[u].insert(v);
						g[v].insert(u);
					}
				}
			}
		}
		n = g.size();
		vector<int>vis(n, 0);
		for (int i = 0; i < n; i++) {
			if (vis[i] == 0) {
				if (dfs(i, -1, vis, g)) {
					return 1;
				}
			}
		}
		return 0;
	}
};