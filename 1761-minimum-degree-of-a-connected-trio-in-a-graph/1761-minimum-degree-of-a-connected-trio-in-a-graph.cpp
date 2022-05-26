class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& e) {
		vector<int>deg(n, 0);
		vector<vector<int>>mat(n, vector<int>(n, 0));
		for (int i = 0; i < e.size(); i++) {
			int u = e[i][0] - 1, v = e[i][1] - 1;
			mat[u][v] = 1;
			mat[v][u] = 1;
			deg[u]++; deg[v]++;
		}
		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (mat[i][j] && mat[i][k] && mat[k][j]) {
						ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
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