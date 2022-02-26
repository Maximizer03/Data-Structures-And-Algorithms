class Solution {
public:
    int calc(int i, int j, int n,vector<vector<int>>&dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=1e9;
        for(int k=i;k<=j;k++){
            ans=min(ans,k+   max(  calc(i,k-1,n,dp),calc(k+1,j,n,dp) )  );
        }
        return dp[i][j]=ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return calc(1,n,n,dp);
    }
};