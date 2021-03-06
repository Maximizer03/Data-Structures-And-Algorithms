class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& e) {
		vector<vector<int>>g(n);
		vector<int>deg(n, 0);
		vector<vector<int>>mat(n, vector<int>(n, 0));
		for (int i = 0; i < e.size(); i++) {
			int u = e[i][0] - 1, v = e[i][1] - 1;
			g[u].push_back(v);
			g[v].push_back(u);
			mat[u][v] = 1; mat[v][u] = 1;
			deg[u]++; deg[v]++;
		}
		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			for (int j : g[i]) {
				if (j > i) {
					for (int k : g[j]) {
						if (k > j) {
							if (mat[i][k]) {
								ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
							}

						}
					}
				}
			}
		}
		if (ans == 1e9) {
			return -1;
		}
		return ans;
	}
};