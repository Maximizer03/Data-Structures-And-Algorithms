class Solution {
public:
	int minDistance(string s1, string s2) {
		int n = s1.size(), m = s2.size();
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == n) {
					dp[i][j] = m - j;
				}
				if (j == m) {
					dp[i][j] = n - i;
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				int ans = 1e9;
				int op1 = dp[i + 1][j] + 1;
				int op2 = dp[i][j + 1] + 1;
				int op3 = 1e9;
				if (s1[i] == s2[j]) {
					op3 = dp[i + 1][j + 1];
				}
				ans = min({op1, op2, op3});
				dp[i][j] = ans;
			}
		}
		return dp[0][0];
	}
};