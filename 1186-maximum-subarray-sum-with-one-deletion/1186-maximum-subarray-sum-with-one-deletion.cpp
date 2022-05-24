class Solution {
public:
	int maximumSum(vector<int>& a) {
		int n = a.size();
		int ans = -2e9;
		vector<int>p(n, -1e9), s(n, -1e9);
		p[0] = a[0];
		for (int i = 1; i < n; i++) {
			p[i] = max(a[i], a[i] + p[i - 1]);
		}
		s[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			s[i] = max(a[i], a[i] + s[i + 1]);
		}
		// either max subarray ending at posn i
		// either max subarray starting at pos i
		// either leaving the ith element and taking max subarray ending at pos i-1 and max sub starting at i+1
        
		for (int i = 0; i < n; i++) {
			vector<int>v;
			v.push_back(p[i]);
			v.push_back(s[i]);
			if (i > 0 && i + 1 < n) {
				v.push_back(p[i - 1] + s[i + 1]);
			}
			sort(begin(v), end(v));
			ans = max(ans, v.back());
		}
		return ans;
	}
};