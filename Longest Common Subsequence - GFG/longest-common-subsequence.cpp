// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int calc(int i, int j, int n, int m, string s1, string s2, vector<vector<int>>&dp){
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans=1+calc(i+1,j+1,n,m,s1,s2,dp);
        }
        else{
            int left= calc(i+1,j,n,m,s1,s2,dp);
            int right= calc(i,j+1,n,m,s1,s2,dp);
            ans=max(left,right);
        }
        return dp[i][j]=ans;
    }
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return calc(0,0,n,m,s1,s2,dp);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends