// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int calc(int i, int sum, int n,vector<int>&w, vector<int>&v, int W,
                                                    vector<vector<int>>&dp){
        if(i==n){
            if(sum<=W){
                return 0;
            }
            else{
                return INT_MIN;
            }
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int ans=calc(i+1,sum,n,w,v,W,dp);
        if(sum+w[i]<=W){
            ans=max(ans,calc(i+1,sum+w[i],n,w,v,W,dp)+v[i]);
        }
        return dp[i][sum]=ans;
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<int>w(n),v(n);
       for(int i=0;i<n;i++){
           w[i]=wt[i];
           v[i]=val[i];
       }
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return calc(0,0,n,w,v,W,dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends