class TreeAncestor {
	vector<vector<int>>dp;
	vector<int>dep;
public:
	void dfs(int v, int par, vector<vector<int>>&g) {
		for (auto &u : g[v]) {
			if (u != par) {
				dep[u] = dep[v] + 1;
				dfs(u, v, g);
			}
		}
	}
	TreeAncestor(int n, vector<int>& parent) {
		dp = vector<vector<int>>(n, vector<int>(21, 0));
		vector<vector<int>>g(n);
		for (int i = 0; i < n; i++) {
			if (parent[i] != -1) {
				int u = i;
				int v = parent[i];
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		for (int i = 0; i < n; i++) {
			dp[i][0] = parent[i];
		}
		dep = vector<int>(n, 0);
		dfs(0, -1, g);
		for (int j = 1; j < 21; j++) {
			for (int i = 0; i < n; i++) {
				if (dep[i] < (1 << j)) {
					dp[i][j] = 0;
				}
				else {
					dp[i][j] = dp[dp[i][j - 1]][j - 1];
				}
			}
		}
	}
	int getKthAncestor(int node, int k) {
		if (dep[node] < k) {
			return -1;
		}
		int nd = node;
		for (int i = 0; i < 21; i++) {
			int bit = (1 << i)&k;
			if (bit > 0) {
				nd = dp[nd][i];
			}
		}
		return nd;
	}
};