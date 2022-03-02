class Solution {
public:
    int calc(int i, int prev, vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(i==n){
            return 0;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int ans=0;
        if(prev){
            ans=max(ans,calc(i+1,0,nums,dp));
        }
        else{
            ans=max(ans,calc(i+1,0,nums,dp));
            ans=max(ans,calc(i+1,1,nums,dp)+nums[i]);
        }
        return dp[i][prev]=ans;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return calc(0,0,nums,dp);
    }
};