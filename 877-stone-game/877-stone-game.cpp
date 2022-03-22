class Solution {
public:
    int dp[505][505][2];
    int calc(int i, int j, int p,vector<int>&a){
        if(i>j){
            return 0;
        }
        if(dp[i][j][p]!=-1){
            return dp[i][j][p];
        }
        int ans=0;
        if(p==1){
            ans=max(calc(i+1,j,0,a)+a[i],calc(i,j-1,0,a)+a[j]);
        }
        else{
            ans=min(calc(i+1,j,1,a),calc(i,j-1,1,a));
        }
        return dp[i][j][p]=ans;
    }
    bool stoneGame(vector<int>& a) {
        int sum=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        memset(dp,-1,sizeof(dp));
        int alice=calc(0,n-1,1,a);
        return alice> sum-alice;
    }
};