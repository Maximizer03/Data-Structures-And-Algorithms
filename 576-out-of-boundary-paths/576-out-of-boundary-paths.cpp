class Solution {
public:
	int dp[55][55][55];
	int mod = 1e9 + 7;
	int calc(int x, int y, int n, int m, int k) {
		if (x >= n || x < 0 || y >= m || y < 0) {
			return (k >= 0);
		}
		if (k == 0) {
			return 0;
		}
		if (dp[x][y][k] != -1) {
			return dp[x][y][k];
		}
		vector<int>dx = {1, -1, 0, 0};
		vector<int>dy = {0, 0, 1, -1};
		long long ans = 0;
		for (int r = 0; r < 4; r++) {
			ans = (ans % mod + calc(x + dx[r], y + dy[r], n, m, k - 1) % mod) % mod;
		}
		return dp[x][y][k] = (int)ans;
	}
	int findPaths(int n, int m, int k, int sx, int sy) {
		memset(dp, -1, sizeof(dp));
		return calc(sx, sy, n, m, k);
	}
};