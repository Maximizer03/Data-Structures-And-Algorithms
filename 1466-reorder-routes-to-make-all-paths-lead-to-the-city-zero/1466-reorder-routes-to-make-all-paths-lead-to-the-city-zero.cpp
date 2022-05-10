class Solution {
public:
	void dfs(int v, int par, vector<vector<int>>&g, vector<pair<int, int>>&p) {
		for (auto &u : g[v]) {
			if (u != par) {
				p.push_back({u, v});
				dfs(u, v, g, p);
			}
		}
	}
	int minReorder(int n, vector<vector<int>>& adj) {
		vector<vector<int>>g(n);
		set<pair<int, int>>s;
		for (auto &x : adj) {
			int u = x[0], v = x[1];
			s.insert({u, v});
			g[v].push_back(u);
			g[u].push_back(v);
		}
		vector<pair<int, int>>p;
		dfs(0, -1, g, p);

		sort(begin(adj), end(adj));
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s.find(p[i]) == s.end()) {
				cnt++;
			}
		}
		return cnt;
	}
};