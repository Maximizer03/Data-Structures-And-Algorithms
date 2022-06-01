class Solution {
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
		queue<pair<int, int>>q;
		vector<vector<int>>dp(n, vector<int>(2, 1e9));
		vector<vector<pair<int, int>>>g(n);
		// 0 for red and 1 for blue
		for (auto &x : redEdges) {
			int u = x[0], v = x[1];
			g[u].push_back({v, 0});
		}
		for (auto &x : blueEdges) {
			int u = x[0], v = x[1];
			g[u].push_back({v, 1});
		}
		set<pair<int, int>>vis;
		dp[0][0] = dp[0][1] = 0;
        vis.insert({0,1});
        vis.insert({0,0});
		vis.insert({0, -1});
		q.push({0, -1});
		int steps = 0;
		while (!q.empty()) {
			int s = q.size();
			for (int i = 0; i < s; i++) {
				int v = q.front().first;
				int col = q.front().second;
				q.pop();
				if (col == -1) {
					for (auto &[u, c] : g[v]) {
						if (vis.find({u, c}) == vis.end()) {
							vis.insert({u, c});
							dp[u][c] = steps + 1;
							q.push({u, c});
						}
					}
				}
				else {
					for (auto &[u, c] : g[v]) {
						if (c != col && vis.find({u, c}) == vis.end()) {
							vis.insert({u, c});
							dp[u][c] = steps + 1;
							q.push({u, c});
						}
					}
				}
			}
			steps++;
		}
		vector<int>ans;
		for (int i = 0; i < n; i++) {
			int x = min(dp[i][0], dp[i][1]);
			if (x != 1e9) {
				ans.push_back(x);
			}
			else {
				ans.push_back(-1);
			}
		}
		return ans;
	}
};