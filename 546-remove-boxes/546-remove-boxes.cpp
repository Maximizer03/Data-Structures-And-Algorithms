class Solution {
public:
	int dp[105][105][105];
	int calc(int i, int j, int ex, vector<int>&c, vector<int>&f) {
		if (i > j) {
			return 0;
		}
		if (dp[i][j][ex] != -1) {
			return dp[i][j][ex];
		}
		int len = f[i] + ex;
		int ans = calc(i + 1, j, 0, c, f) + len * len;
		for (int k = i + 1; k <= j; k++) {
			if (c[i] == c[k]) {
				ans = max(ans, calc(k, j, ex + f[i], c, f) + calc(i + 1, k - 1, 0, c, f));
			}
		}
		return dp[i][j][ex] = ans;
	}
	int removeBoxes(vector<int>& b) {
		int n = b.size();
		vector<int>c, f;
		int col = b[0], cnt = 1;
		for (int i = 1; i < n; i++) {
			if (b[i] == col) {
				cnt++;
			}
			else {
				c.push_back(col);
				f.push_back(cnt);
				cnt = 1;
				col = b[i];
			}
		}
		c.push_back(col);
		f.push_back(cnt);
		n = c.size();
		memset(dp, -1, sizeof(dp));
		return calc(0, n - 1, 0, c, f);
	}
};