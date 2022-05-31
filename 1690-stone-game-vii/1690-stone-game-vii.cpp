class Solution {
public:
    vector<int>p;
    int dp[1005][1005];
    int get(int l, int r){
        int res= p[r];
        if(l){
            res-=p[l-1];
        }
        return res;
    }
    int calc(int l, int r,vector<int>&arr){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans= get(l+1,r)-calc(l+1,r,arr);
        ans= max(ans, get(l,r-1)-calc(l,r-1,arr));
        return dp[l][r]=ans;
    }
    int stoneGameVII(vector<int>& s) {
        int n=s.size();
        p.resize(n);
        p[0]=s[0];
        for(int i=1;i<n;i++){
            p[i]=p[i-1]+s[i];
        }
        memset(dp,-1,sizeof(dp));
        return calc(0,n-1,s);
    }
};