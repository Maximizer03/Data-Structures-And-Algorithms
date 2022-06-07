class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        int dp[n + 1][3];
        dp[n][0] = 0;
        dp[n][1] = dp[n][2] = -1e9;
        for (int i = n - 1; i >= 0; i--) {
            for (int r = 0; r < 3; r++) {
                int ans = dp[i + 1][r];
                ans = max(ans, dp[i + 1][(r + nums[i]) % 3] + nums[i]);
                dp[i][r] = ans;
            }
        }
        return dp[0][0];
    }
};