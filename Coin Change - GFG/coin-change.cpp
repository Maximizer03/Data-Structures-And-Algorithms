// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long calc(int i, int sum, int n, int m,vector<int>&c,vector<vector<long long>>&dp){
        if(i==m){
            return (sum==n);
        }
        if(sum>n){
            return 0;
        }
        if(sum==n){
            return 1;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        long long ans=0;
        ans+=calc(i,sum+c[i],n,m,c,dp);
        ans+=calc(i+1,sum,n,m,c,dp);
        return dp[i][sum]=ans;
    }
    long long int count(int S[], int m, int n) {
        vector<int>c;
        for(int i=0;i<m;i++){
            c.push_back(S[i]);
        }
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,-1));
        return calc(0,0,n,m,c,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends