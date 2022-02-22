class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1'){
                    dp[i][j]=1;
                    vector<int>v;
                    if(i-1>=0){
                        v.push_back(dp[i-1][j]);
                    }
                    else{
                        v.push_back(0);
                    }
                    if(j-1>=0){
                        v.push_back(dp[i][j-1]);
                    }
                    else{
                        v.push_back(0);
                    }
                    if(i>=1 && j>=1){
                        v.push_back(dp[i-1][j-1]);
                    }
                    else{
                        v.push_back(0);
                    }
                    sort(v.begin(),v.end());
                        dp[i][j]=max(dp[i][j],1+v[0]);
                }                
                mx=max(mx,dp[i][j]);
            }
        }
        return mx*mx;
    }
};