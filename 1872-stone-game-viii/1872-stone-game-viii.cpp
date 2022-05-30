class Solution {
public:
	int stoneGameVIII(vector<int>& s) {
		int n = s.size();
		vector<int>p(n);
		p[0] = s[0];
		for (int i = 1; i < n; i++) {
			p[i] = p[i - 1] + s[i];
		}
		vector<int>dp(n);
		int prev = p[n - 1];
		for (int i = n - 3; i >= 0; i--) {
			int cur = max(prev, p[i + 1] - prev);
			prev = cur;
		}
		return prev;
	}
};