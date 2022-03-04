// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
public:
	int binpow(int x, int n) {
		int ans = 1;
		for(int i=0;i<n;i++) {
			ans *= x;
		}
		return ans;
	}
	vector<int>sum;
	int solve(int n) {
		if (n == 1) {
			return 1;
		}
		if (n == 0) {
			return 0;
		}
		if (n < 0) {
			return 0;
		}
		int lg = log2(n);
		int ans = sum[lg];
		int p = binpow(2, lg);
		ans += (n - p) + solve(n - p);
		return ans;
	}
	int countBits(int n) {
		for (int i = 0; i <= 31; i++) {
			int y = 1 + i * binpow(2, i - 1);
			sum.push_back(y);
		}
		solve(n);
		// code here
	}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends