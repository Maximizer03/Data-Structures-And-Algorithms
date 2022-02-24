class Solution {
public:
    int calc(int i, bool own, vector<int>&prices, int fee,vector<vector<int>>&dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][own]!=-1){
            return dp[i][own];
        }
        if(own){
            int op1= prices[i]+ calc(i+1,0,prices,fee,dp);
            int op2= calc(i+1,1,prices,fee,dp);
            return dp[i][own]=max(op1,op2);
        }
        else{
            int op1= -prices[i]-fee+ calc(i+1,1,prices,fee,dp);
            int op2= calc(i+1,0,prices,fee,dp);
            return dp[i][own]=max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return calc(0,0,prices,fee,dp);
    }
};