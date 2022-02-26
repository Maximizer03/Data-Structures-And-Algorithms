class Solution {
public:
	void dfs(int v, int p, vector<int>&dp, vector<int>&sub, vector<vector<int>>&g) {
		int sum = 1;
		dp[v]=0;
		for (auto &u : g[v]) {
			if (u != p) {
				dfs(u, v, dp, sub, g);
				sum += sub[u];
				dp[v]+=sub[u]+dp[u];
			}
		}
		sub[v] = sum;
	}
	void dfs2(int v, int p, vector<int>&dp, vector<int>&sub, vector<vector<int>>&g, vector<int>&ans) {
        ans[v]=dp[v];
		for (auto &u : g[v]) {
			if (u != p) {
				dp[v] = dp[v] - dp[u] -sub[u];
				dp[u] = dp[u]+ dp[v]+ dp.size()-sub[u];
				dfs2(u, v, dp, sub, g, ans);
				dp[u]-= (dp[v]+dp.size()-sub[u]);
				dp[v]+= (dp[u]+sub[u]);
			}
		}
	}
	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		int m = edges.size();
		vector<vector<int>>g(n);
		for (int i = 0; i < m; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int>dp(n);
		vector<int>sub(n, 0);
		dfs(0, -1, dp, sub, g);
		vector<int>ans(n);
		dfs2(0, -1, dp, sub, g, ans);
		return ans;
	}
};