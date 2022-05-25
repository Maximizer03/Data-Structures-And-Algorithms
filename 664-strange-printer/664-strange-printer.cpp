class Solution {
public:
	int dp[105][105][105];
	int calc(int i, int j, int ex, vector<int>&c) {
		if (i > j) {
			return 0;
		}
		if (dp[i][j][ex] != -1) {
			return dp[i][j][ex];
		}
		int ans = calc(i + 1, j, 0, c) + 1;
		for (int k = i + 1; k <= j; k++) {
			if (c[i] == c[k]) {
				ans = min(ans, calc(k, j, ex + 1,c) + calc(i + 1, k - 1, 0,c));
			}
		}
		return dp[i][j][ex] = ans;
	}
	int strangePrinter(string s) {
		int n = s.size();
		string t = "";
		t += s[0];
		for (int i = 1; i < n; i++) {
			if (s[i] != t.back()) {
				t.push_back(s[i]);
			}
		}
		s = t;
		n = s.size();
		vector<int>c;
		for (int i = 0; i < n; i++) {
			int no = s[i] - 'a' + 1;
			c.push_back(no);
		}
		memset(dp, -1, sizeof(dp));
		return calc(0, n - 1, 0, c);
	}
};