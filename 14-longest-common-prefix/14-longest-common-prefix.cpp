class Solution {
public:
	bool calc(int len, vector<string>&s) {
		int n = s.size();
		string st = s[0].substr(0, len);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i].substr(0, len) == st) {
				cnt++;
			}
		}
		return (cnt == n);
	}
	string longestCommonPrefix(vector<string>& strs) {
		int n = strs.size();
		int mx = 0;
		for (int i = 0; i < n; i++) {
            int si= strs[i].size();
			mx = max(mx, si);
		}
		string ans = "";
		if (mx == 0) {
			return ans;
		}
		int l = 1, r = mx;
		while (l <= r) {
			int m = (l + r) / 2;
			if (calc(m, strs)) {
				l = m + 1;
				ans = strs[0].substr(0, m);
			}
			else {
				r = m - 1;
			}
		}
		return ans;
	}
};