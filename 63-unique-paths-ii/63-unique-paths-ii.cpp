class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        if(g[0][0]==1 || g[n-1][m-1]==1){
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    if(i>0){
                        dp[i][j]+=dp[i-1][j];
                    }
                    if(j>0){
                        dp[i][j]+=dp[i][j-1];
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};