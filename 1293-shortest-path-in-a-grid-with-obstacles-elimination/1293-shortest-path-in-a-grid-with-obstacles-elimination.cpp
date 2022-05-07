class Solution {
public:
	int shortestPath(vector<vector<int>>& grid, int k) {
		int n = grid.size(), m = grid[0].size();
		set< array<int, 3> > s;
		s.insert({0, 0, k});
		queue<array<int, 3>>q;
		q.push({0, 0, k});
		vector<int>dx = {1, -1, 0, 0};
		vector<int>dy = {0, 0, 1, -1};
		int steps = 0;
		while (!q.empty()) {
			int si = q.size();
			for (int i = 0; i < si; i++) {
				int x = q.front()[0], y = q.front()[1], obs = q.front()[2];
				if (x == n - 1 && y == m - 1) {
					return steps;
				}
				q.pop();
				for (int r = 0; r < 4; r++) {
					int xx = dx[r] + x, yy = dy[r] + y;
					if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
						if (grid[xx][yy] == 1) {
							if (obs > 0) {
								if (s.find({xx, yy, obs - 1}) == s.end()) {
									q.push({xx, yy, obs - 1});
									s.insert({xx, yy, obs - 1});
								}
							}
						}
						else {
							if (s.find({xx, yy, obs}) == s.end()) {
								q.push({xx, yy, obs});
								s.insert({xx, yy, obs});
							}
						}
					}
				}
			}
			steps++;
		}
		return -1;
	}
};