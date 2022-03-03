class Solution {
public:
    int calc(int i, int cnt, vector<vector<int>>&costs,vector<vector<int>>&dp){
        int n=costs.size();
        if(cnt>n/2){
            return 1e5;
        }
        if(i==n){
            if(cnt==n/2){
                return 0;
            }
            else{
                return 1e5;
            }
        }
        if(dp[i][cnt]!=-1){
            return dp[i][cnt];
        }
        int ans=min(calc(i+1,cnt+1,costs,dp)+costs[i][0],calc(i+1,cnt,costs,dp)+costs[i][1]);
        return dp[i][cnt]=ans;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<vector<int>>dp(n+1,vector<int>(n/2+1,-1));
        return calc(0,0,costs,dp);
    }
};