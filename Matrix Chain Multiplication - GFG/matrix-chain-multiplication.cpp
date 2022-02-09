// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int calc(int i, int j, vector<int>&c,vector<vector<int>>&dp){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int cost= calc(i,k,c,dp)+ calc(k+1,j,c,dp)+ c[i-1]*c[k]*c[j];
            ans=min(ans,cost);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int n, int arr[])
    {
        vector<int>c(n);
        for(int i=0;i<n;i++){
            c[i]=arr[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return calc(1,n-1,c,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends