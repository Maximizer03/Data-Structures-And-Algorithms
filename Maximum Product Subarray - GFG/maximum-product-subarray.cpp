// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
        long long pmaxi=nums[0];
        long long pmini=nums[0];
        long long mx=nums[0];
        for(int i=1;i<n;i++){
            long long x= nums[i];
            long long cmaxi=max({x,x*pmaxi,x*pmini});
            long long cmini=min({x,x*pmaxi,x*pmini});
            mx=max({mx,cmaxi,cmini});
            pmaxi=cmaxi;
            pmini=cmini;
        }
        return mx;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends