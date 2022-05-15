class Solution {
public:
	int ans;
	void calc(int l, int r, string &s) {
		while (l >= 0 && r < s.size() && s[l] == s[r]) {
			ans++;
			l--;
			r++;
		}
	}
	int countSubstrings(string s) {
		int n = s.size();
		ans = 0;
		for (int p = 0; p < n; p++) {
			calc(p, p, s);
			calc(p, p + 1, s);
		}
		return ans;
	}
};