class Solution {
public:
	string t;
	long long dp[55][1005];
	long long mod;
	void calci(int i, string &s, char cur, vector<string>&res, int n) {
		if (i == n) {
			res.push_back(s);
			return;
		}
		for (int j = 0; j < 3; j++) {
			if (t[j] != cur) {
				s += t[j];
				calci(i + 1, s, t[j], res, n);
				s.pop_back();
			}
		}
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
	long long calc(int v, int col, int m, vector<vector<int>>&g) {
		if (col == m - 1) {
			return 1;
		}
        if(dp[v][col]!=-1){
            return dp[v][col];
        }
		long long ans = 0;
		for (auto &u : g[v]) {
			ans = (ans % mod + calc(u, col + 1, m, g) % mod);
		}
		return dp[v][col]= (int)ans;
	}
	int colorTheGrid(int n, int m) {
		t = "RBG";
		vector<string>res;
		string s = "";
		char cur = '*';
		calci(0, s, cur, res, n);
		int x = res.size();
		vector<vector<int>>g(55);
		for (int i = 0; i < x; i++) {
			for (int j = i + 1; j < x; j++) {
				if (chk(res[i], res[j])) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		memset(dp, -1, sizeof(dp));
		mod = 1e9 + 7;
		long long ans = 0;
		for (int i = 0; i < x; i++) {
			ans = (ans % mod + calc(i, 0, m, g) % mod) % mod;
		}
		return (int)ans;
	}
};