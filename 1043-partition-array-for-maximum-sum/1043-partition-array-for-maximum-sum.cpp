class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int n = arr.size();
		vector<long long>dp(n + 1, 0);
		dp[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			long long ans = 0, mx = 0, cnt = 0;
			int maxi = min(i + k - 1, n - 1);
			for (int j = i; j <= maxi; j++) {
				mx = max(mx, (long long)arr[j]);
				cnt++;
				ans = max(ans, dp[j + 1] + mx * cnt);
			}
			dp[i] = ans;
		}
		return dp[0];
	}
};