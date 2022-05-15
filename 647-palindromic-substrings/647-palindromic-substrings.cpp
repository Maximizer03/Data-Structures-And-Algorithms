class Solution {
public:
	int calc(int i, int j, vector<vector<int>>&dp, string &s) {
		if (i > j) {
			return 0;
		}
		if (i == j) {
			return 1;
		}
		if (i + 1 == j) {
			return (s[i] == s[i + 1]);
		}
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		int ans = calc(i + 1, j - 1, dp, s) & (s[i] == s[j]);
		return dp[i][j] = ans;
	}
	int countSubstrings(string s) {
		int n = s.size(), ans = 0;
		vector<vector<int>>dp(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (calc(i, j, dp, s)) {
					ans++;
				}
			}
		}
		return ans;
	}
};