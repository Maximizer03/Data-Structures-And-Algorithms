class Solution {
public:
	int longestCommonSubsequence(string s1, string s2) {
		int n = s1.size(), m = s2.size();
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == n || j == m) {
					dp[i][j] = 0;
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				int ans = 0;
				int op1 = 0;
				int op2 = 0;
				if (s1[i] == s2[j]) {
					op1 = dp[i + 1][j + 1] + 1;
				}
				else {
					op2 = max(dp[i + 1][j], dp[i][j + 1]);
				}
				ans = max({op1, op2});
				dp[i][j] = ans;
			}
		}
		return dp[0][0];
	}
};