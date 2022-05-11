class Solution {
public:
	int countRestrictedPaths(int n, vector<vector<int>>& edges) {
		vector<vector<pair<long long , long long>>>g(n + 1);
		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0], v = edges[i][1], w = edges[i][2];
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		int src = n;
		priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>q;
		// (dist,src)
		q.push({0, src});
		vector<long long>dist(n + 1, 1e12);
		long long mod = 1e9 + 7;
		vector<long long>dp(n + 1, 0);
		dp[n] = 1;
		dist[src] = 0;
		while (!q.empty()) {
			long long cost = q.top().first;
			long long v = q.top().second;
			q.pop();
			if (cost > dist[v]) {
				continue;
			}
			for (auto &[u, w] : g[v]) {
				if (dist[v] + w < dist[u]) {
					dist[u] = dist[v] + w;
					q.push({dist[u], u});
				}
				if (dist[u] > dist[v]) {
					dp[u] = (dp[u] % mod + dp[v] % mod) % mod;
				}
			}
		}
		return (int)dp[1];
	}
};