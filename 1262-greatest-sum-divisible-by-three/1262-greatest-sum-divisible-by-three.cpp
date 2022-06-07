class Solution {
public:
    int dp[100005][3];
    int calc(int i, int r, vector<int>&nums){
        int n=nums.size();
        if(i==n){
            if(r==0){
                return 0;
            }
            else{
                return -1e9;
            }
        }
        if(dp[i][r]!=-1){
            return dp[i][r];
        }
        int ans= calc(i+1,r,nums);
        ans= max(ans, calc(i+1, (r+nums[i])%3,nums)+ nums[i]);
        return dp[i][r]=ans;
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return calc(0,0,nums);
    }
};