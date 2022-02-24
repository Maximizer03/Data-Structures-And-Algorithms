class Solution {
public:
    int kInversePairs(int n, int k) {
        if(k> (n*(n-1))/2){
            return 0;
        }
        if(k==0 || k==(n*(n-1))/2){
            return 1;
        }
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,0));
        dp[0][0]=1;
        long long mod=1e9+7;
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
            for(int j=1;j<=k;j++){
                dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
                if(j-i>=0){
                    dp[i][j]= (dp[i][j]-dp[i-1][j-i]+mod)%mod;
                }
            }
        }
        return (int)dp[n][k];
    }
};