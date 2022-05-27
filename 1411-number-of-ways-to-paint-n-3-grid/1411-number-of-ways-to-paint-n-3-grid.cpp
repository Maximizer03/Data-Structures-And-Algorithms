class Solution {
public:
	string t;
	long long mod,dp[12][5005];
	void calci(int i, char cur, string &s, vector<string>&res) {
		if (i == 3) {
			res.push_back(s);
			return;
		}
		for (int j = 0; j < 3; j++) {
			if (t[j] != cur) {
				s += t[j];
				calci(i + 1, t[j], s, res);
				s.pop_back();
			}
		}
	}
	long long calc(int v, int row, vector<vector<int>>&g, int n) {
		if (row == n - 1) {
			return 1;
		}
		if (dp[v][row] != -1) {
			return dp[v][row];
		}
		long long ans = 0;
		for (auto &u : g[v]) {
			ans = (ans % mod + calc(u, row + 1, g, n) % mod) % mod;
		}
		return dp[v][row] = ans;
	}
	bool chk(string &s, string &t) {
		int n = s.size();
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) {
				return false;
			}
		}
		return true;
	}
	int numOfWays(int n) {
		t = "RGY";
		string s = "";
		char cur = '*';
		vector<string>res;
		calci(0, cur, s, res);
		int x = res.size();
		mod = 1e9 + 7;
		vector<vector<int>>g(x + 1);
		for (int i = 0; i < x; i++) {
			for (int j = i + 1; j < x; j++) {
				if (chk(res[i], res[j])) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		memset(dp, -1, sizeof(dp));
		long long ans = 0;
		for (int i = 0; i < x; i++) {
			ans = (ans % mod + calc(i, 0, g, n) % mod) % mod;
		}
		return (int)ans;
	}
};