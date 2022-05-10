class Solution {
public:
	long long maxAlternatingSum(vector<int>& nums) {
		int n = nums.size();
		vector<vector<long long>>dp(n + 1, vector<long long>(2));
		dp[n][0] = dp[n][1] = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int par = 0; par <= 1; par++) {
				long long ans = dp[i + 1][par];
				long long x = nums[i];
				if (par % 2) {
					x *= -1;
				}
				ans = max(ans, dp[i + 1][par ^ 1] + x);
				dp[i][par] = ans;
			}
		}
		return dp[0][0];
	}
};