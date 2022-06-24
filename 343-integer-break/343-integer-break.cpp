class Solution {
public:
    int integerBreak(int n) {
        vector<long long>dp(n+1,1);
        for(long long i=2;i<=n;i++){
            for(long long j=1;j<=i-1;j++){
                long long op1= max(j,dp[j]);
                long long op2= max(i-j,dp[i-j]);
                dp[i]=max(dp[i],op1*op2);
            }
        }
        return dp[n];
    }
};