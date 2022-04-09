class Solution {
public:
	int numSplits(string s) {
		int n = s.size();
		set<char>left;
		vector<int>dp1(n, 0), dp2(n, 0);
		for (int i = 0; i < n; i++) {
			left.insert(s[i]);
			dp1[i] = left.size();
		}
		left.clear();
		for (int i = n - 1; i >= 0; i--) {
			left.insert(s[i]);
			dp2[i] = left.size();
		}
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (dp1[i] == dp2[i + 1]) {
				ans++;
			}
		}
		return ans;
	}
};