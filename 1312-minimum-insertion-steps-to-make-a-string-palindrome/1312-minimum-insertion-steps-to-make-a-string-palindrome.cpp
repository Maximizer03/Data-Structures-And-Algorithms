class Solution {
public:
    int calc(int l,int r, string &s,vector<vector<int>>&dp){
        if(l>r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans=INT_MAX;
        if(s[l]==s[r]){
            ans=calc(l+1,r-1,s,dp);
        }
        else{
            ans=1+min(calc(l+1,r,s,dp),calc(l,r-1,s,dp));
        }
        return dp[l][r]=ans;
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return calc(0,n-1,s,dp);
    }
};