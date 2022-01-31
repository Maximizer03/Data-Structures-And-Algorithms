// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
      int n=s.size(),m=t.size();
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      const long long mod=1e9+7;
      function<long long(int,int)>calc= [&](int i, int j){
          if(j==m){
              return 1;
          }
          if(i==n){
              return int(j>=m);
          }
          if(dp[i][j]!=-1){
              return dp[i][j];
          }
          long long ans=0;
          if(s[i]==t[j]){
              ans= (calc(i+1,j+1)%mod+calc(i+1,j)%mod)%mod;
          }
          else{
              ans=(calc(i+1,j)%mod);
          }
          return dp[i][j]=ans;
      };
      return calc(0,0);
    }
};
 


// { Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}  // } Driver Code Ends