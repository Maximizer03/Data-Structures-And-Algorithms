class Solution {
private:
    vector<int>dp;
public:
    int calc(int i, string s){
        int n=s.size();
        if(i==n){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans= calc(i+1,s);
        if(i+1<n){
            if(s[i]=='1' || s[i]=='2'&& s[i+1]<='6'){
                ans+=calc(i+2,s);
            }
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        dp.resize(s.size()+1,-1);
        return calc(0,s);
    }
};