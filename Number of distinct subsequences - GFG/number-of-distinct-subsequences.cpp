// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int n=s.size();
	    vector<int>dp(n+1,0);
	    dp[0]=1;
	    const long long mod=1e9+7;
	    vector<long long>ind(26,-1);
	    for(int i=1;i<=n;i++){
	        int v=s[i-1]-'a';
	        dp[i]=(dp[i-1]%mod*2%mod)%mod;
	        long long rep=0;
	        if(ind[v]!=-1){
	            rep= dp[ind[v]-1];
	        }
	        dp[i]= (dp[i]%mod - rep%mod + mod)%mod;
	        ind[v]=i;
	    }
	    return dp[n];
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends