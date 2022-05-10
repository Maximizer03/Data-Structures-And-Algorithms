class Solution {
public:
    long long dp[100005][2];
    long long calc(int i, int p, vector<int>&nums){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][p]!=-1){
            return dp[i][p];
        }
        long long ans= calc(i+1,p,nums);
        long long x= nums[i];
        if(p%2){
            x*=-1;
        }
        ans=max(ans,calc(i+1,p^1,nums)+x);
        return  dp[i][p]= ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return calc(0,0,nums);
    }
};