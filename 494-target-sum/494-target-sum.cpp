class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int,int>>dp(n+1);
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(auto &x:dp[i-1]){
                dp[i][x.first+nums[i-1]]+=x.second;
                dp[i][x.first-nums[i-1]]+=x.second;
            }
        }
        return dp[n][target];
    }
};