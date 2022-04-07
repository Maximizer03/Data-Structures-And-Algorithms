class Solution {
public:
	int swimInWater(vector<vector<int>>& grid) {
		int n = grid.size();
		using ppii = pair<int, pair<int, int>>;
		priority_queue<ppii, vector<ppii>, greater<ppii>>q;
		q.push({grid[0][0], {0, 0}});
		vector<int>dx = {1, -1, 0, 0};
		vector<int>dy = {0, 0, 1, -1};
		vector<vector<int>>dist(n, vector<int>(n, 1e9));
		dist[0][0] = grid[0][0];
		while (!q.empty()) {
			int D = q.top().first;
			int x = q.top().second.first;
			int y = q.top().second.second;
			q.pop();
			if (D > dist[x][y]) {
				continue;
			}
			if (x == n - 1 && y == n - 1) {
				return D;
			}
			for (int k = 0; k < 4; k++) {
				int xx = x + dx[k];
				int yy = y + dy[k];
				if (xx < 0 || yy < 0 || xx >= n || yy >= n) {
					continue;
				}
				int mx = max(D, grid[xx][yy]);
				if (mx < dist[xx][yy]) {
					q.push({mx, {xx, yy}});
					dist[xx][yy] = mx;
				}
			}
		}
		return -1;
	}
};