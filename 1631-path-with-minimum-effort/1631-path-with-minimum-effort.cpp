class Solution {
public:
	int minimumEffortPath(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		using ppii = pair<int, pair<int, int>>;
		priority_queue<ppii, vector<ppii>, greater<ppii>>q;
		q.push({0, {0, 0}});
		vector<int>dx = {1, -1, 0, 0};
		vector<int>dy = {0, 0, 1, -1};
		vector<vector<int>>dist(n, vector<int>(m, 1e9));
		dist[0][0] = 0;
		while (!q.empty()) {
			int d = q.top().first;
			int x = q.top().second.first;
			int y = q.top().second.second;
			q.pop();
			if (d > dist[x][y]) {
				continue;
			}
			if (x == n - 1 && y == m - 1) {
				return d;
			}
			for (int k = 0; k < 4; k++) {
				int xx = x + dx[k];
				int yy = y + dy[k];
				if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
					int mx = max(d, abs(grid[x][y] - grid[xx][yy]));
					if (mx < dist[xx][yy]) {
						q.push({mx, {xx, yy}});
						dist[xx][yy] = mx;
					}
				}
			}
		}
		return -1;
	}
};