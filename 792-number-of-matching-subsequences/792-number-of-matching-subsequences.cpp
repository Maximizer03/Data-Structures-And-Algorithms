class Solution {
public:
	bool calc(string &s, vector<vector<int>>&g) {
		int n = s.size();
		if (g[s[0] - 'a'].size() == 0) {
			return false;
		}
		int st = g[s[0] - 'a'][0];
		int j = 1;
		while (j < n) {
			int cn = s[j] - 'a';
			int ub = upper_bound(begin(g[cn]), end(g[cn]), st) - g[cn].begin();
			if (ub != g[cn].size()) {
				st = g[cn][ub];
				j++;
			}
			else {
				return false;
			}
		}
		return true;
	}
	int numMatchingSubseq(string s, vector<string>& words) {
		vector<vector<int>>g(26);
		int n = s.size();
		for (int i = 0; i < n; i++) {
			g[s[i] - 'a'].push_back(i);
		}
		int cnt = 0;
		for (string x : words) {
			if (calc(x, g)) {
				cnt++;
			}
		}
		return cnt;
	}
};