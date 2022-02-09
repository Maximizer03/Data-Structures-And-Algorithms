// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long calc(int n, int r, vector<vector<long long>>&dp, long long mod){
        if(r>n){
            return 0;
        }
        if(r==0 || r==n){
            return 1;
        }
        if(dp[n][r]!=-1){
            return dp[n][r];
        }
        return dp[n][r]=(calc(n-1,r,dp,mod)%mod+calc(n-1,r-1,dp,mod)%mod)%mod;
    }
    int nCr(int n, int r){
        // vector<vector<int>>dp(n+1,vector<int>(r+1));
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=min(i,r);j++){
        //         if(j==0 || j==i){
        //             dp[i][j]=1;
        //         }
        //         else{
        //             dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        //         }
        //     }
        // }
        // return dp[n][r];
        int mx=max(n,r);
        long long mod=1e9+7;
        vector<vector<long long>>dp(mx+1,vector<long long>(mx+1,-1));
        int ans=calc(n,r,dp,mod);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends