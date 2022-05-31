class Solution {
public:
	void calc(int i, string &s, int n, string &cur, vector<string>&res, vector<vector<char>>&g) {
		if (i == n) {
			res.push_back(cur);
			return;
		}
		int d = s[i] - '0';
		for (int j = 0; j < g[d].size(); j++) {
			char ch = g[d][j];
			cur += ch;
			calc(i + 1, s, n, cur, res, g);
			cur.pop_back();
		}
	}
	vector<string> letterCombinations(string s) {
		int n = s.size();
		vector<string>res;
		if (n == 0) {
			return res;
		}
		vector<vector<char>>g(10);
		int k = 0;
		for (int i = 2; i <= 9; i++) {
			int cnt = 3;
			if (i == 7 || i == 9) {
				cnt = 4;
			}
			for (int j = 0; j < cnt; j++) {
				char ch = k + 'a';
				g[i].push_back(ch);
				k++;
			}
		}
		string cur = "";
		calc(0, s, n, cur, res, g);
		return res;
	}
};