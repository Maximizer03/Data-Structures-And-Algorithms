class Solution {
public:
	int dfs(int l, int r, string &s, vector<vector<int>>&A) {
		if (l > r) {
			return 0;
		}
		if (l == r) {
			return 1;
		}
		if (l + 1 == r) {
			return (s[l] == s[r]);
		}
		if (A[l][r] != -1) {
			return A[l][r];
		}
		int ans = (s[l] == s[r] && dfs(l + 1, r - 1, s, A));
		return A[l][r] = ans;
	}
	int minCut(string s) {
		int n = s.size();
		vector<vector<int>>A(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				A[i][j] = dfs(i, j, s, A);
			}
		}
		vector<int>dp(n + 1);
		dp[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			int ans = INT_MAX;
			for (int j = i; j < n; j++) {
				if (A[i][j] > 0) {
					ans = min(ans, 1 + dp[j + 1]);
				}
			}
			dp[i] = ans;
		}
		return dp[0] - 1;
	}
};