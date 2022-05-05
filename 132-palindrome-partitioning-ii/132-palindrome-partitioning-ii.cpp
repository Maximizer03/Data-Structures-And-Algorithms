class Solution {
public:
	int minCut(string s) {
		int n = s.size();
		vector<vector<int>>A(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			A[i][i] = 1;
		}
		for (int x = 0; x < n; x++) {
			int i = 0, j = x + 1;
			while (j < n) {
				if (i + 1 == j) {
					A[i][j] = (s[i] == s[j]);
				}
				else {
					A[i][j] = (s[i] == s[j] && A[i + 1][j - 1]);
				}
				i++;
				j++;
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