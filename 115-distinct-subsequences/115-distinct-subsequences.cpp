class Solution {
public:
	int numDistinct(string s, string t) {
		int n = s.size(), m = t.size();
		vector<vector<int>>dp(n + 5, vector<int>(m + 5, -1));
		function<int(int, int)>calc = [&](int i, int j) {
			if (j == m) {
				return 1;
			}
			if (i == n) {
				return int(j>=m);
			}
			if (dp[i][j] != -1) {
				return dp[i][j];
			}
			int ans = 0;
			if (s[i] == t[j]) {
				ans = calc(i + 1, j) + calc(i + 1, j + 1);
			}
			else {
				ans = calc(i + 1, j);
			}
			return dp[i][j] = ans;
		};
		return calc(0, 0);
	}
};