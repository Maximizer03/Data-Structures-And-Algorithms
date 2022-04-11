class Solution {
public:
	int calc(int i, vector<int>&dp, vector<int>&cnt, int mx) {
		if (i >= mx + 1) {
			return 0;
		}
		if (dp[i] != -1) {
			return dp[i];
		}
		int ans = calc(i + 1, dp, cnt, mx);
		if (cnt[i] > 0) {
			ans = max(ans, calc(i + 2, dp, cnt, mx) + cnt[i] * i);
		}
		return dp[i] = ans;
	}
	int deleteAndEarn(vector<int>& nums) {
		int n = nums.size();
		int mx = 0;
		for (int i = 0; i < n; i++) {
			mx = max(mx, nums[i]);
		}
		vector<int>cnt(mx + 5, 0);
		for (int i = 0; i < n; i++) {
			cnt[nums[i]]++;
		}
		vector<int>dp(mx + 5, -1);
		return calc(1, dp, cnt, mx);
	}
};