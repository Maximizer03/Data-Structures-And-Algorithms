class Solution {
public:
	bool canPartition(vector<int>& nums) {
		long long sum = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			sum += nums[i];
		}
		if (sum % 2) {
			return false;
		}
		sum = sum / 2;
		vector<vector<int>>dp(n + 1, vector<int>(sum + 1, 0));
		dp[0][0] = 1;

		for (int i = 1; i <= n; i++) {
			dp[i][0] = 1;
			for (int j = 1; j <= sum; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j - nums[i - 1] >= 0) {
					dp[i][j] = (dp[i][j] | dp[i - 1][j - nums[i - 1]]);
				}
			}
		}
		return dp[n][sum];
	}
};