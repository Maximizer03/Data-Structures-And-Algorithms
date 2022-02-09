// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int calc(int l, int r, vector<vector<int>>&dp,string &s){
        if(l>r){
            return 0;
        }
        if(l==r){
            return 1;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans=0;
        if(s[l]==s[r]){
            if(l==r){
                ans=max(ans,1+calc(l+1,r-1,dp,s));
            }
            else{
                ans=max(ans,2+calc(l+1,r-1,dp,s));
            }
        }
        else{
            ans=max({ans,calc(l+1,r,dp,s),calc(l,r-1,dp,s)});
        }
        return dp[l][r]=ans;
    }
    int longestPalinSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return calc(0,n-1,dp,s);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends