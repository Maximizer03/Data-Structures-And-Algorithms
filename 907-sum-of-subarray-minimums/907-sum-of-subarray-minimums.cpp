class Solution {
public:
	int sumSubarrayMins(vector<int>& a) {
		int n = a.size();
		vector<int>ngr(n, n), ngl(n, -1), st;
		for (int i = n - 1; i >= 0; i--) {
			while (st.size() > 0 && a[st.back()] > a[i]) {
				st.pop_back();
			}
			if (!st.empty()) {
				ngr[i] = st.back();
			}
			st.push_back(i);
		}
		while (!st.empty()) {
			st.pop_back();
		}
		for (int i = 0; i < n; i++) {
			while (!st.empty() && a[st.back()] >= a[i]) {
				st.pop_back();
			}
			if (!st.empty()) {
				ngl[i] = st.back();
			}
			st.push_back(i);
		}
		long long ans = 0,mod=1e9+7;
		for (int i = 0; i < n; i++) {
            long long alpha= (i - ngl[i])%mod;
            long long beta= (ngr[i] - i)%mod;
			long long t = (alpha*beta)%mod;
			ans= (ans%mod + t%mod*a[i]%mod)%mod;
		}
		return ans;
	}
};