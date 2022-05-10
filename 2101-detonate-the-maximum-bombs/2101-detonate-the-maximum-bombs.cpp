class Solution {
public:
	int ans;
	void dfs(int v, int p, vector<set<int>>&g, vector<int>&vis) {
		vis[v] = 1;
		ans++;
		for (auto &u : g[v]) {
			if (!vis[u]) {
				dfs(u, v, g, vis);
			}
		}
	}
	int maximumDetonation(vector<vector<int>>& b) {
		int n = b.size();
		vector<set<int>>g(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n && j != i; j++) {
				long long x1 = b[i][0], y1 = b[i][1], r1 = b[i][2];
				long long x2 = b[j][0], y2 = b[j][1], r2 = b[j][2];
				if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r1 * r1) {
					g[i].insert(j);
				}
				if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r2 * r2) {
					g[j].insert(i);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			ans = 0;
			vector<int>vis(n, 0);
			dfs(i, -1, g, vis);
			cnt = max(cnt, ans);
		}
		return cnt;
	}
};