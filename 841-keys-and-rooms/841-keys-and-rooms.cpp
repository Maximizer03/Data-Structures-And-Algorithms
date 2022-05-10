class Solution {
public:
	void dfs(int v, int p, vector<int>&vis, vector<vector<int>>&g) {
		vis[v] = 1;
		for (auto &u : g[v]) {
			if (!vis[u]) {
				dfs(u, v, vis, g);
			}
		}
	}
	bool canVisitAllRooms(vector<vector<int>>& g) {
		int n = g.size();
		vector<int>vis(n, 0);
		dfs(0, -1, vis, g);
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				return 0;
			}
		}
		return 1;
	}
};