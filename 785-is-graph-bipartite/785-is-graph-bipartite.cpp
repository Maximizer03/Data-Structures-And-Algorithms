class Solution {
public:
	bool dfs(int v, vector<int>&c, vector<vector<int>>&g) {
		if (c[v] == -1) {
			c[v] = 1;
		}
		for (auto &u : g[v]) {
			if (c[u] == -1) {
				c[u] = 1 - c[v];
				if (!dfs(u, c, g)) {
					return false;
				}
			}
			else if (c[v] == c[u]) {
				return false;
			}
		}
		return true;
	}
	bool isBipartite(vector<vector<int>>& d) {
		int n = d.size();
		vector<vector<int>>g(n);
		for (int i = 0; i < n; i++) {
			for (auto &x : d[i]) {
				int u = i, v = x;
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		vector<int>c(n + 1, -1);
		for (int i = 0; i < n; i++) {
			if (c[i] == -1) {
				if (!dfs(i, c, g)) {
					return false;
				}
			}
		}
		return true;
	}
};