class Solution {
public:
    int calc(int i, int target, vector<int>&nums,vector<unordered_map<int,int>>&dp){
        int n=nums.size();
        if(i==n){
            return (target==0);
        }
        if(dp[i].find(target)!=dp[i].end()){
            return dp[i][target];
        }
        return dp[i][target]=calc(i+1,target+nums[i],nums,dp)+
                             calc(i+1,target-nums[i],nums,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int,int>>dp(n);
        return calc(0,target,nums,dp);
    }
};