class Solution {
public:
	double dp[30][30][101];
	double calc(int n, int k, int x, int y) {
		if (x >= n || x < 0 || y >= n || y < 0) {
			return 0;
		}
		if (k == 0) {
			return 1;
		}
		if (dp[x][y][k] != 0) {
			return dp[x][y][k];
		}
		vector<int>dx = {1, 1, 2, 2, -1, -1, -2, -2};
		vector<int>dy = { -2, 2, 1, -1, 2, -2, 1, -1};
		double ans = 0;
		for (int r = 0; r < 8; r++) {
			ans += calc(n, k - 1, x + dx[r], y + dy[r]);
		}
		return dp[x][y][k] = ans / 8.0;
	}
	double knightProbability(int n, int k, int r, int c) {
		memset(dp, 0, sizeof(dp));
		return calc(n, k, r, c);
	}
};