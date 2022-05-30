class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
		int n = mat.size(), m = mat[0].size();
		int dp[n][m];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j] = mat[i][j];
				if (i) {
					dp[i][j] += dp[i - 1][j];
				}
			}
		}
		int ans = INT_MIN;
		for (int r1 = 0; r1 < n; r1++) {
			for (int r2 = r1; r2 < n; r2++) {
				vector<int>v;
				for (int j = 0; j < m; j++) {
					int cur = dp[r2][j];
					if (r1) {
						cur -= dp[r1 - 1][j];
					}
					v.push_back(cur);
				}
				int u = v.size();
				set<int>s;
				s.insert(0);
				int a = INT_MIN;
				int sum = 0;
				for (int i = 0; i < u; i++) {
					sum += v[i];
					auto it = s.lower_bound(sum - k);
					if (it != s.end()) {
						a = max(a, sum - *it);
					}
					s.insert(sum);
				}
                ans=max(ans, a);
			}
		}
		return ans;
	}
};