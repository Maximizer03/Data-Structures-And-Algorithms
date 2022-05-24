class Solution {
public:
    // IF ADJACENT NODE OF A NODE IS COLORED AND IS COLORED WITH THE SAME COLOR THEN GRAPH IS NOT PARTITTE
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
	bool possibleBipartition(int n, vector<vector<int>>& d) {
		vector<vector<int>>g(n);
		for (int i = 0; i < d.size(); i++) {
			int u = d[i][0], v = d[i][1];
			u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int>c(n, -1);
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