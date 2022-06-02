// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	int mx=0;
    	for(int i=0;i<n;i++){
    	    mx=max(mx,dep[i]);
    	}
    	vector<int>a(mx+5,0);
    	for(int i=0;i<n;i++){
    	    int l=arr[i];
    	    int r= dep[i];
    	    a[l]++;
    	    a[r+1]--;
    	}
    	int ans=0;
    	for(int i=1;i<=mx;i++){
    	    a[i]+=a[i-1];
    	    ans=max(ans,a[i]);
    	    
    	}
    	return ans;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends