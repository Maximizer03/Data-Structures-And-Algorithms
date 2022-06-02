// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[505];
    int calc(int i, vector<int>&nums, int k, int n){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=1e9,sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(j>i){
                sum++;
            }
            if(sum>k){
                break;
            }
            int rem= k-sum;
            int cost= rem*rem;
            if(j==n-1){
                cost=0;
            }
            ans= min(ans, calc(j+1,nums,k,n)+cost);
        }
        return dp[i]=ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return calc(0,nums,k,n);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends