class Solution {
public:
	int countPaths(int n, vector<vector<int>>& roads) {
		long long m = roads.size();

		vector<long long>d(n, 1e15);
		vector<long long>num(n, 0);
		vector<bool>vis(n, 0);
		vector<vector<pair<long long, long long>>>g(n);

		long long mod = 1e9 + 7;

		for (int i = 0; i < m; i++) {
			long long u = roads[i][0];
			long long v = roads[i][1];
			long long w = roads[i][2];
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}

		// (dist,node)
		priority_queue<pair<long , long>, vector<pair<long , long>>, greater<pair<long , long>>>q;

		q.push({0, 0});
		d[0] = 0;
		num[0] = 1;

		while (!q.empty()) {
			int v = q.top().second;
			q.pop();
			if (!vis[v]) {
				vis[v] = 1;
				for (pair<long long , long long > pr : g[v]) {
					long long   u = pr.first;
					long long  w = pr.second;
					if (d[v] + w < d[u]) {
						d[u] = d[v] + w;
						num[u] = num[v];
						q.push({d[u], u});
					}
					else if ( d[u] == d[v] + w) {
						num[u] = (num[u] % mod + num[v] % mod ) % mod;
						q.push({d[u], u});
					}
				}
			}
		}
		return num[n - 1];
	}
};