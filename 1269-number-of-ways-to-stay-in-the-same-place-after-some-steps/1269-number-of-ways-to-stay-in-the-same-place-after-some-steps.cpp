class Solution {
public:
	int dp[505][505];
	int mod = 1e9 + 7;
	int calc(int i, int n, int k, int mx) {
		if (i > mx) {
			return 0;
		}
		if (k == 0) {
			return (i == 0);
		}
		if (dp[i][k] != -1) {
			return dp[i][k];
		}
		int ans = 0;
		for (int j = -1; j <= 1; j++) {
			if (j + i >= 0 && j + i < n) {
				ans = (ans % mod + calc(j + i, n, k - 1, mx) % mod) % mod;
			}
		}
		return dp[i][k] = ans;
	}
	int numWays(int k, int n) {
		memset(dp, -1, sizeof(dp));
		return calc(0, n, k, k);
	}
};