class Solution {
public:
	int calc(string s, int k) {
		int n = s.size();
		if (k > n) {
			return 0;
		}
		vector<int>cnt(26, 0);
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}
		int flg = 1;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > 0) {
				flg = (flg & (cnt[i] >= k) );
			}
		}
		return (flg == 1) ? s.size() : 0;
	}
	int longestSubstring(string s, int k) {
		int n = s.size();
		if (k > n) {
			return 0;
		}
		vector<int>cnt(26, 0);
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}
		int i = 0;
		vector<string>a;
		string t = "";
		while (i < n) {
			if (cnt[s[i] - 'a'] >= k) {
				t += s[i];
				i++;
			}
			else {
				a.push_back(t);
				t = "";
				i++;
			}
		}
		if (t.size()) {
			a.push_back(t);
		}
		int mx = 0;
		for (auto &x : a) {
            int val= calc(x,k);
			mx = max(mx, val);
			if (val == 0) {
				mx = max(mx, longestSubstring(x, k));
			}
		}
		return mx;
	}
};