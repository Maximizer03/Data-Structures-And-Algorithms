class Solution {
public:
    int calc(int i, int j, string &s,vector<vector<int>>&dp){
        int n=s.size();
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        if(s[i]==s[j]){
            ans=max(ans,2+calc(i+1,j-1,s,dp));
        }
        else{
            ans=max({ans,calc(i+1,j,s,dp),calc(i,j-1,s,dp)});
        }
        return dp[i][j]= ans;
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return max(1,calc(0,n-1,s,dp));
    }
};