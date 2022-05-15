class Solution {
public:
	long long dp[505];
	int calc(int i, int k, int n, vector<int>&arr) {
		if (i == n) {
			return 0;
		}
		if (dp[i] != -1) {
			return dp[i];
		}
		int ans = 0;
		int mx = 0, cnt = 0;
		int maxi = min(i + k - 1, n - 1);
		for (int j = i; j <= maxi; j++) {
			mx = max(mx, arr[j]);
			cnt++;
			ans = max(ans, calc(j + 1, k, n, arr) + mx * cnt);
		}
		return dp[i] = ans;
	}
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int n = arr.size();
		memset(dp, -1, sizeof(dp));
		return calc(0, k, n, arr);
	}
};