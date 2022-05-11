class Solution {
public:
	int dijkstra(int src, vector<vector<pair<int, int>>>&g) {
		int n = g.size();
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
		// (dist,src)
		q.push({0, src});
		vector<int>dist(n, 1e9);
		dist[src] = 0;
		while (!q.empty()) {
			int cost = q.top().first;
			int v = q.top().second;
			q.pop();
			if (cost > dist[v]) {
				continue;
			}
			for (auto &[u, w] : g[v]) {
				if (dist[v] + w < dist[u]) {
					dist[u] = dist[v] + w;
					q.push({dist[u], u});
				}
			}
		}
		return dist[n - 1];
	}
	int minCost(vector<vector<int>>& g) {
		int n = g.size(), m = g[0].size();
		vector<int>dx = {0, 0, 1, -1};
		vector<int>dy = {1, -1, 0, 0};
		vector<vector<pair<int, int>>>graph(n * m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				g[i][j]--;
				for (int r = 0; r < 4; r++) {
					int c = 0;
					if (r != g[i][j]) {
						c++;
					}
					int x = dx[r] + i, y = dy[r] + j;
					if (x >= 0 && x < n && y >= 0 && y < m) {
						int u = i * m + j;
						int v = x * m + y;
						int w = c;
						graph[u].push_back({v, w});
					}
				}
			}
		}
		return dijkstra(0, graph);
	}
};