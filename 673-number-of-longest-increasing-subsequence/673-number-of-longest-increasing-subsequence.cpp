class Solution {
public:
	int findNumberOfLIS(vector<int>& a) {
		int n = a.size();
		vector<int>dp(n, 1), cnt(n, 1);
		// dp[i]=> len of LIS ending at i
		// cnt[i]=> no of LIS ending at i
		int l = 0, f = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] > a[j]) {
					if (dp[j] + 1 == dp[i]) {
						cnt[i] += cnt[j];
					}
					if (dp[j] + 1 > dp[i]) {
						dp[i] = 1 + dp[j];
						cnt[i] = cnt[j];
					}

				}
			}
			if (dp[i] == l) {
				f += cnt[i];
			}
			if (dp[i] > l) {
				l = dp[i];
				f = cnt[i];
			}
		}
		return f;
	}
};