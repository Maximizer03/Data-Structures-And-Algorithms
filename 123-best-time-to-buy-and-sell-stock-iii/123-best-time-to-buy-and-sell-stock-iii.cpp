class Solution {
public:
	long long dp[100005][2][3];
	long long calc(int i, int b, int k, vector<int>&p) {
		if (i == p.size()) {
			return 0;
		}
		if (dp[i][b][k] != -1) {
			return dp[i][b][k];
		}
		long long ans = 0;
		if (!b) {
			ans = calc(i + 1, b, k, p);
			ans = max(ans, calc(i + 1, 1, k, p) - p[i]);
		}
		else {
			ans = calc(i + 1, b, k, p);
			if (k > 0) {
				ans = max(ans, calc(i + 1, 0, k - 1, p) + p[i]);
			}
		}
		return dp[i][b][k] = ans;
	}
	int maxProfit(vector<int>& p) {
		memset(dp, -1, sizeof(dp));
		return calc(0, 0, 2, p);
	}
};