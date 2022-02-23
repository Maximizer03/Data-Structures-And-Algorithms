class Solution {
public:
    int calc(int i, int j, vector<vector<int>>&mat,vector<vector<int>>&dp){
        int n=mat.size(),m=mat[0].size();
        if(i==n || j==m){
            return 1e9;
        }
        if(i==n-1 && j==m-1){
            if(mat[i][j]<=0){
                return 1-mat[i][j];
            }
            else{
                return 1;
            }
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=calc(i,j+1,mat,dp);
        int down= calc(i+1,j,mat,dp);
        
        int cost= min(right,down)-mat[i][j];
        if(cost<=0){
            return dp[i][j]=1;
        }
        else{
            return dp[i][j]=cost;
        }
    }
    int calculateMinimumHP(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return calc(0,0,mat,dp);
    }
};