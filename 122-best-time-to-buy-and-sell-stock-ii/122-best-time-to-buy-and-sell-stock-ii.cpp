class Solution {
public:
    int dp[30005][2];
    int calc(vector<int>&prices,int i, int cnt){
        int n=prices.size();
        if(i>=n){
            return 0;
        }
        if(dp[i][cnt]!=-1){
            return dp[i][cnt];
        }
        int ans=0;
        if(cnt==0){
            ans=max(calc(prices,i+1,0),calc(prices,i+1,1)-prices[i]);
        }
        else{
            ans=max(calc(prices,i+1,1),calc(prices,i+1,0)+prices[i]);
        }
        return dp[i][cnt]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return calc(prices,0,0);
    }
};