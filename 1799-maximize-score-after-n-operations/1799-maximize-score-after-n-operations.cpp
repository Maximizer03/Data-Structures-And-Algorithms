class Solution {
public:
	int g[15][15];
	int dp[(1 << 15)];
	int calc(int mask, int n) {
		if (mask == (1 << n) - 1) {
			return 0;
		}
		if (dp[mask] != -1) {
			return dp[mask];
		}
		int ans = 0;
		int idx = __builtin_popcount(mask) / 2 + 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				int b1 = (1 << i)&mask;
				int b2 = (1 << j)&mask;
				if (b1 == b2 && b1 == 0) {
					int n_mask = (mask | (1 << i));
					n_mask = (n_mask | (1 << j));
					ans = max(ans, calc(n_mask, n) + g[i][j] * idx);
				}
			}
		}
		return dp[mask] = ans;
	}
	int maxScore(vector<int>& a) {
		int n = a.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = __gcd(a[i], a[j]);
			}
		}
		memset(dp, -1, sizeof(dp));
		return calc(0, n);
	}
};