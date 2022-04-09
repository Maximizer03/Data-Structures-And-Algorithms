class Solution {
public:
	int dp[100005][27];
	int calc(int i, int p, string &s, vector<int>&T) {
		if (i == s.size()) {
			return 0;
		}
		if (dp[i][p] != -1) {
			return dp[i][p];
		}
		int ans = 1e9;
		int cur = s[i] - 'a';
		if (p == cur) {
			ans = min(ans, calc(i + 1, p, s, T) + T[i]);
		}
		else {
			ans = min({ans, calc(i + 1, cur, s, T), calc(i + 1, p, s, T) + T[i]});
		}
		return dp[i][p] = ans;
	}
	int minCost(string s, vector<int>& T) {
		memset(dp, -1, sizeof(dp));
		return calc(0, 26, s, T);
	}
};