class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        function<int(int)>calc= [&](int i){
            if(i==n){
                return 1;
            }
            if(dp[i]!=-1){
                return dp[i];
            }
            int ans=0;
            if((i+1<=n)){
                ans+=calc(i+1);
            }
             if((i+2<=n)){
                ans+=calc(i+2);
            }
            return dp[i]=ans;
        };
        return calc(0);
    }
};