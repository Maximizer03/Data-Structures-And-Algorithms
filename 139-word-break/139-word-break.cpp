class Solution {
public:
    int calc(int i, string s, unordered_map<string,int>&m,vector<int>&dp){
        int n=s.size();
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        for(int j=i;j<n;j++){
            string t=s.substr(i,j-i+1);
            if(m.find(t)!=m.end()){
                ans= ans | calc(j+1,s,m,dp);
            }
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>m;
        for(auto &word:wordDict){
            m[word]++;
        }
        vector<int>dp(s.size(),-1);
        return calc(0,s,m,dp);
    }
};