class Solution {
public:
    int getMoneyAmount(int n) {
        // dp[i][j]=> min cost to guarantee win for range [i,j]
        // dp[i][j]= min(max(dp[i][pivot-1], dp[pivot+1][j])+pivot);
        vector<vector<int>>dp(n+5,vector<int>(n+5,0));
        for(int i=1;i<=n;i++){
            dp[i][i]=0;
        }
        for(int l=2;l<=n;l++){
            for(int s=1;s<=n-l+1;s++){
                int e=s+l-1;
                int ans=INT_MAX;
                for(int p=s;p<=e;p++){
                    ans=min(ans,max(dp[s][p-1],dp[p+1][e])+p);
                }
                dp[s][e]=ans;
            }
        }
        return dp[1][n];
    }
};