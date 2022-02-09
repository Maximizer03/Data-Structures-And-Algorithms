// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int calc(int i, int n, int arr[], int tar, int sum,vector<vector<int>>&dp){
        if(sum>tar){
            return 0;
        }
        if(sum==tar){
            return 1;
        }
        if(i==n){
            return (sum==tar);
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int  ans=    calc(i+1,n,arr,tar,sum,dp);
        ans= (ans | calc(i+1,n,arr,tar,sum+arr[i],dp));
        return dp[i][sum]=ans;
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2==1){
            return 0;
        }
        int tar=sum/2;
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        if(calc(0,N,arr,tar,0,dp)){
            return 1;
        }
        else{
            return 0;
        }
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends