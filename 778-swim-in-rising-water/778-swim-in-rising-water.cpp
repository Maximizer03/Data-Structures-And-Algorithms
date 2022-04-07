class Solution {
public:
	int swimInWater(vector<vector<int>>& grid) {
		int n = grid.size();
		using ppii = pair<int, pair<int, int>>;
		priority_queue<ppii, vector<ppii>, greater<ppii>>q;
		q.push({grid[0][0], {0, 0}});
		vector<int>dx = {1, -1, 0, 0};
		vector<int>dy = {0, 0, 1, -1};
		vector<vector<bool>>vis(n, vector<bool>(n, false));
        vis[0][0]=1;
		while (!q.empty()) {
			int dist = q.top().first;
			int x = q.top().second.first;
			int y = q.top().second.second;
			q.pop();
			if (x == n - 1 && y == n - 1) {
				return dist;
			}
			for (int k = 0; k < 4; k++) {
				int xx = x + dx[k];
				int yy = y + dy[k];
				if (xx < 0 || yy < 0 || xx >= n || yy >= n) {
					continue;
				}
				int mx = max(dist, grid[xx][yy]);
				if (vis[xx][yy]==false) {
					q.push({mx, {xx, yy}});
                    vis[xx][yy]=1;
				}
			}
		}
		return -1;
	}
};