class Solution {
public:
    bool calc(int i, int sum, vector<int>&nums,vector<vector<int>>&dp){
        if(sum<0){
            return 0;
        }
        int n=nums.size();
        if(i==n){
            return (sum==0);
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int ans=calc(i+1,sum,nums,dp) | calc(i+1,sum-nums[i],nums,dp);
        return dp[i][sum]=ans;
    }
    bool canPartition(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2){
            return false;
        }
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return calc(0,sum/2,nums,dp);
    }
};