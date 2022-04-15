class Solution {
public:
	int dp[5005][4][4][4];
	int calc(int r, int c1, int c2, int c3, int n) {
		if (r == n) {
			return 1;
		}
		if (dp[r][c1][c2][c3] != -1) {
			return dp[r][c1][c2][c3];
		}
		int mod = 1e9 + 7;
		long long ans = 0;
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				for (int k = 1; k <= 3; k++) {
					if (i != j && j != k) {
						if (i != c1 && j != c2 && k != c3) {
							ans = (ans % mod + calc(r + 1, i, j, k, n) % mod) % mod;
						}
					}
				}
			}
		}
		return dp[r][c1][c2][c3] = ans;
	}
	int numOfWays(int n) {
		memset(dp, -1, sizeof(dp));
		return calc(0, 0, 0, 0, n);
	}
};