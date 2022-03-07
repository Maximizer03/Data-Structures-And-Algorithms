class Solution {
public:
    long long calc(int i,vector<int>&p, vector<int>&sk, vector<long long>&dp){
        int n=p.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long ans=calc(i+1,p,sk,dp);
        int nxt= i+sk[i]+1;
        ans=max(ans,calc(nxt,p,sk,dp)+(long long)p[i]);
        return dp[i]=ans;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<int>p(n),sk(n);
        for(int i=0;i<n;i++){
            p[i]=questions[i][0];
            sk[i]=questions[i][1];
        }
        long long mn=-1;
        vector<long long>dp(n+1,mn);
        return calc(0,p,sk,dp);   
    }
};