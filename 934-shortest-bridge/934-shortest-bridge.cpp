class Solution {
public:
	set<pair<int, int>>s;
	void dfs(int i, int j, int n, int m, vector<vector<int>>&grid, queue<pair<int, int>>&q) {
		if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == 0) {
			return;
		}
		grid[i][j] = 0;
		s.insert({i, j});
		q.push({i, j});
		dfs(i + 1, j, n, m, grid, q);
		dfs(i - 1, j, n, m, grid, q);
		dfs(i, j + 1, n, m, grid, q);
		dfs(i, j - 1, n, m, grid, q);
	}
	int shortestBridge(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		queue<pair<int, int>>q;
		bool flg = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					dfs(i, j, n, m, grid, q);
					flg = 1;
					break;
				}
			}
			if (flg) {
				break;
			}
		}
		int d = 0;
		vector<int>dx = {1, -1, 0, 0};
		vector<int>dy = {0, 0, 1, -1};
		while (!q.empty()) {
			int si = q.size();
			for (int i = 0; i < si; i++) {
				int x = q.front().first;
				int y = q.front().second;
				if (grid[x][y] == 1) {
					return d - 1;
				}
				q.pop();
				for (int k = 0; k < 4; k++) {
					int xx = x + dx[k];
					int yy = y + dy[k];
					if (xx >= 0 && xx < n && yy >= 0 && yy < m && s.find({xx, yy}) == s.end()) {
						q.push({xx, yy});
						s.insert({xx, yy});
					}
				}
			}
			d++;
		}
		return 0;
	}
};