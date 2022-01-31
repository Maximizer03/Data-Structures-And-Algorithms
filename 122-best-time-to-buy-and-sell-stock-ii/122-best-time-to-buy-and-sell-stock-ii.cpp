class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        function<int(int,int)> calc=[&](int i, int cnt){
            if(i==n){
                return 0;
            }
            if(dp[i][cnt]!=-1){
                return dp[i][cnt];
            }
            int ans;
            if(cnt==0){
                ans=max(calc(i+1,0),calc(i+1,1)-p[i]);
            }
            else{
                ans=max(calc(i+1,1),calc(i+1,0)+p[i]);
            }
            return dp[i][cnt]=ans;
        };
        return calc(0,0);
    }
};