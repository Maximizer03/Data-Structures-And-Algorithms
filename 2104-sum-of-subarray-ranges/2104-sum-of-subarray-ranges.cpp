class Solution {
public:
	long long subArrayRanges(vector<int>& a) {
		int n = a.size();
		vector<int>ngr(n, n), nsr(n, n), ngl(n, -1), nsl(n, -1), st;
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && a[st.back()] < a[i]) {
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
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && a[st.back()] > a[i]) {
				st.pop_back();
			}
			if (!st.empty()) {
				nsr[i] = st.back();
			}
			st.push_back(i);
		}
		while (!st.empty()) {
			st.pop_back();
		}
		for (int i = 0; i < n; i++) {
			while (!st.empty() && a[st.back()] <= a[i]) {
				st.pop_back();
			}
			if (!st.empty()) {
				ngl[i] = st.back();
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
				nsl[i] = st.back();
			}
			st.push_back(i);
		}
		while (!st.empty()) {
			st.pop_back();
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			long long leftMax = i - ngl[i], rightMax = ngr[i] - i;
			long long leftMin = i - nsl[i], rightMin = nsr[i] - i;
			ans += (leftMax * rightMax - leftMin * rightMin) * a[i];
		}
		return ans;
	}
};