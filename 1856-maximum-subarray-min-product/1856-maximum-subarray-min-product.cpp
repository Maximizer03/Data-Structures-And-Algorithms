class Solution {
public:
	int maxSumMinProduct(vector<int>& A) {
		int n = A.size();
		vector<int>st;
		vector<int>r(n, n), l(n, -1);
		for (int i = n - 1; i >= 0; i--) {
			while (st.size() > 0 && A[st.back()] >= A[i]) {
				st.pop_back();
			}
			if (!st.empty()) {
				r[i] = st.back();
			}
			st.push_back(i);
		}
		st.clear();
		for (int i = 0; i < n; i++) {
			while (st.size() > 0 && A[st.back()] >= A[i]) {
				st.pop_back();
			}
			if (!st.empty()) {
				l[i] = st.back();
			}
			st.push_back(i);
		}
		vector<long long >pref(n, 0);
		pref[0] = A[0];
		for (int i = 1; i < n; i++) {
			pref[i] = pref[i - 1] + A[i];
		}
		long long p = -1e18;
		for (int i = 0; i < n; i++) {
			long long sum = pref[r[i] - 1];
			if (l[i] >= 0) {
				sum -= pref[l[i]];
			}
			long long pro = sum * (long long)(A[i]);
			p = max(p, pro);
		}
		long long mod = 1e9 + 7;
		return p % mod;
	}
};