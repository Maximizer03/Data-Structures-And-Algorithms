class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int>res;
        // if anagram is greater than original string 
		if (s.size() < p.size()) {
			return res;
		}
		int n = s.size(), m = p.size();
		vector<int>hs(26, 0), hp(26, 0);
		vector<bool>vis(26, 0);
        
		for (int i = 0; i < m; i++) {
			hp[p[i] - 'a']++;
			vis[p[i] - 'a'] = true;
		}
        
		int cnt = 0;
		for (int i = 0; i < 26; i++) {
			if (hp[i]>0) {
				cnt++;
			}
		}
		int cur = 0;
		for (int i = 0; i < m; i++) {
			int v = s[i] - 'a';
			hs[v]++;
			if (vis[v]) {
				if (hs[v] == hp[v]) {
					cur++;
				}
			}
		}
		if (cur == cnt) {
			res.push_back(0);
		}
		for (int i = 1; i +m <= n; i++) {
			int p1 = s[i - 1] - 'a';
			int p2 = s[i + m - 1] - 'a';
			if (vis[p1]) {
				if (hs[p1] == hp[p1]) {
					cur--;
				}
			}
			hs[p1]--;
			hs[p2]++;
			if (vis[p2]) {
				if (hs[p2] == hp[p2]) {
					cur++;
				}
			}
			if (cur == cnt) {
				res.push_back(i);
			}
		}
		return res;
	}
};