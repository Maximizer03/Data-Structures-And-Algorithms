class Solution {
public:
	int maxSumTwoNoOverlap(vector<int>& arr, int l1, int l2) {
		int n = arr.size();
		int dp[n + 1][2][2];
		memset(dp, -1e9, sizeof(dp));
		dp[n][1][1] = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int p1 = 0; p1 < 2; p1++) {
				for (int p2 = 0; p2 < 2; p2++) {
					int ans = dp[i + 1][p1][p2];
					if (p1 == 0 && i + l1 - 1 < n) {
						int sum = 0;
						for (int j = i; j < i + l1; j++) {
							sum += arr[j];
						}
						ans = max(ans, dp[i + l1][1][p2] + sum);
					}
					if (p2 == 0 && i + l2 - 1 < n ) {
						int sum = 0;
						for (int j = i; j < i + l2; j++) {
							sum += arr[j];
						}
						ans = max(ans, dp[i + l2][p1][1] + sum);
					}
					dp[i][p1][p2] = ans;
				}
			}
		}
		return dp[0][0][0];
	}
};