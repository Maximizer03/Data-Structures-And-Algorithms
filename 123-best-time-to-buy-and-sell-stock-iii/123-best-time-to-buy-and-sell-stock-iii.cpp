class Solution {
public:
	int maxProfit(vector<int>& p) {
		int n = p.size();
		long long dp[n + 1][2][3];
		memset(dp, 0, sizeof(dp));
		for (int i = n - 1; i >= 0; i--) {
			for (int b = 0; b <= 1; b++) {
				for (int k = 0; k <= 2; k++) {
					long long ans = 0;
					if (!b) {
						ans = dp[i + 1][b][k];
						ans = max(ans, dp[i + 1][1][k] - p[i]);
					}
					else {
						ans = dp[i + 1][b][k];
						if (k > 0) {
							ans = max(ans, dp[i + 1][0][k - 1] + p[i]);
						}
					}
					dp[i][b][k] = ans;
				}
			}
		}
		return dp[0][0][2];
	}
};