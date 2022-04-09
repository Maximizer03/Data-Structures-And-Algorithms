class Solution {
public:
	// dp[\U0001d462]  as the number of back-edges passing over the edge between \U0001d462 and its parent.
	// dp[\U0001d462]=(# of back-edges going up from \U0001d462)−(# of back-edges going down from \U0001d462)+∑dp[\U0001d463]\U0001d463 is a child of \U0001d462.
	void dfs(int v, int par, vector<vector<int>>&g, vector<int>&lvl, vector<int>&dp, vector<vector<int>>&ans) {
		dp[v] = 0;
		for (auto &u : g[v]) {
			if (lvl[u] == 0) {
				// edges to child
				lvl[u] = lvl[v] + 1;
				dfs(u, v, g, lvl, dp, ans);
				dp[v] += dp[u];
			}
			else if (lvl[v] > lvl[u]) {
				// edges upwards
				dp[v]++;
			}
			else if (lvl[v] < lvl[u]) {
				// edge downwards
				dp[v]--;
			}
		}
		// the parent edge isn't a back-edge, subtract 1 to compensate
		dp[v]--;
		if (lvl[v] > 1 && dp[v] == 0) {
			ans.push_back({v, par});
		}
	}
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		vector<vector<int>>g(n);
		for (auto &x : connections) {
			int u = x[0], v = x[1];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int>lvl(n, 0);
		lvl[0] = 1;
		vector<int>dp(n, 0);
		vector<vector<int>>ans;
		dfs(0, -1, g, lvl, dp, ans);
		return ans;
	}
};