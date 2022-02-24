class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        for(int len=1;len<=n;len++){
            for(int l=1;l<=n-len+1;l++){
                int r=l+len-1;
                for(int k=l;k<=r;k++){
                    dp[l][r]=max(dp[l][r],dp[l][k-1]+dp[k+1][r]+nums[l-1]*nums[k]*nums[r+1]);
                }
            }
        }
        return dp[1][n];
        
    }
};