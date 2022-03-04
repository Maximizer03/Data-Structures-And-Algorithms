class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        int n=s.size();
        long long ans=0;
        long long mod=1e9+7;
        // dp[i]=> number of unique good subsequences ending at i
        vector<long long >dp(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cnt++;
            }
        }
        int ind=0;
        while(ind<n && s[ind]=='0'){
            ind++;
        }
        if(ind==n){
            return 1;
        }
        int pz=-1,po=ind;
        dp[ind]=1;
        for(int i=ind+1;i<n;i++){
            if(s[i]=='1'){
                dp[i]= (dp[i-1]*2)%mod;
                long long dup=0;
                if(po>0){
                    dup= dp[po-1];
                }
                dp[i]= (dp[i] - dup+mod)%mod;
                po=i;
            }
            else{
                dp[i]=(dp[i-1]*2)%mod;
                long long dup=0;
                if(pz>0){
                    dup=dp[pz-1];
                }
                dp[i]=(dp[i]-dup+mod)%mod;
                pz=i;
            }
        }
        // cout<<dp[n-1]<<endl;
        ans=dp[n-1];
        if(cnt>0){
            ans= (ans+1)%mod;
        }
        return (int)ans;
    }
};