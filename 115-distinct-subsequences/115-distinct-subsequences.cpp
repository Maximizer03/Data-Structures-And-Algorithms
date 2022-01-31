class Solution {
public:
    int dp[1005][1005];
    int calc(int i, int j, string &s, string &t){
        int n=s.size(), m=t.size();
        if(j==m){
            return 1;
        }
        if(i==n){
            return (j>=m);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j]){
            ans= calc(i+1,j,s,t)+calc(i+1,j+1,s,t);
        }
        else{
            ans=calc(i+1,j,s,t);
        }
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return calc(0,0,s,t);
    }
};