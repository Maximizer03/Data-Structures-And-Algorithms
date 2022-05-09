class Solution {
public:
	int numTrees(int n) {
		vector<vector<long long>>dp(40, vector<long long>(40, 0));
		// dp[i][j]=> i C j
		for (int i = 0; i <= 39; i++) {
			dp[i][0] = 1;
		}
		for (int i = 1; i < 40; i++) {
			for (int j = 1; j < 40; j++) {
				long long ans = 0;
				if (i >= j) {
					ans = dp[i - 1][j] + dp[i - 1][j - 1];
				}
				dp[i][j] = ans;
			}
		}
		long long ans = dp[2 * n][n];
		ans /= (n + 1);
		return (int)(ans);
	}
};