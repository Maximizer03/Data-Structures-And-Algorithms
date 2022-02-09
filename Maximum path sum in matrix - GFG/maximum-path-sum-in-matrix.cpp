// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> mat)
    {
        int n=mat.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=mat[0][i];
        }
        int mx=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=dp[i-1][j]+mat[i][j];
                if(j-1>=0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+mat[i][j]);
                }
                if(j+1<n){
                    dp[i][j]=max(dp[i][j],dp[i-1][j+1]+mat[i][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            mx=max(mx,dp[n-1][i]);
        }
        return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends