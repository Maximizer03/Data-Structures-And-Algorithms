class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<int>p(n),sk(n);
        for(int i=0;i<n;i++){
            p[i]=questions[i][0];
            sk[i]=questions[i][1];
        }
        vector<long long>dp(n,0);
        dp[n-1]=p[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=dp[i+1];
            long long prev=0;
            if(i+sk[i]+1<n){
                prev=dp[i+sk[i]+1];
            }
            
            dp[i]=max(dp[i],prev+p[i]);
            
        }
        return dp[0];
    }
};