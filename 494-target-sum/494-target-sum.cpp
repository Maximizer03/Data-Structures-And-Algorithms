class Solution {
public:
    int calc(int i, vector<int>&nums,int sum,vector<unordered_map<int,int>>&dp){
        if(i==nums.size()){
            return sum==0;
        }
        if(dp[i].find(sum)!=dp[i].end()){
            return dp[i][sum];
        }
        int ans= calc(i+1,nums,sum-nums[i],dp)+calc(i+1,nums,sum+nums[i],dp);
        return dp[i][sum]=ans;
    }
    int findTargetSumWays(vector<int>& nums, int sum) {
        vector<unordered_map<int,int>>dp(nums.size());
        return calc(0,nums,sum,dp);
    }
};