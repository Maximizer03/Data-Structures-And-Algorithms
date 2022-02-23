class Solution {
public:
     int calc(int i, int j, int n, int m, string &s, string &t, vector<vector<int>>&dp){
      if(i==n){
          return m-j;
      }
      if(j==m){
          return n-i;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      int ans=INT_MAX;
      if(s[i]==t[j]){
          ans=calc(i+1,j+1,n,m,s,t,dp);
      }
      else{
          int insert=1+calc(i,j+1,n,m,s,t,dp);
          int del = 1+calc(i+1,j,n,m,s,t,dp);
          int repl =1+calc(i+1,j+1,n,m,s,t,dp);
          ans=min({ans,insert,del,repl});
      }
      
      return dp[i][j]=ans;
  }
    int minDistance(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return calc(0,0,n,m,s,t,dp);
    }
};