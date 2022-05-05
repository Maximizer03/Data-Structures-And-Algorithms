class Solution {
public:
	int sumSubarrayMins(vector<int>& a) {
		int n = a.size();
		vector<int>L(n), R(n);
		stack<pair<int, int>>st;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && st.top().first > a[i]) {
				st.pop();
			}
			L[i] = st.empty() ? i + 1 : i - st.top().second;
			st.push({a[i], i});
		}
		while (!st.empty()) {
			st.pop();
		}
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && st.top().first >= a[i]) {
				st.pop();
			}
			R[i] = st.empty() ? n - i : st.top().second - i;
			st.push({a[i], i});
		}
		int ans = 0, mod = 1e9 + 7;
		for (int i = 0; i < n; i++) {
			long long p = (long long)(L[i]) * R[i] * (a[i]);
			ans = (ans % mod + p % mod) % mod;
		}
		return ans;
	}
};