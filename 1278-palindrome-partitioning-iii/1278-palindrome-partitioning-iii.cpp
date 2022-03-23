class Solution {
public:
	long long dp[105][105];
	long long calc(int i, string &s, int k, vector<vector<int>>&cnt) {
		int n = s.size();
		if (i == n) {
			if (k == 0) {
				return 0;
			}
			else {
				return 1e9;
			}
		}
		if (k == 0) {
			return 1e9;
		}
		if (dp[i][k] != -1) {
			return dp[i][k];
		}
		long long ans = 1e9;
		for (int j = i; j < n; j++) {
			long long x = calc(j + 1, s, k - 1, cnt);
			if (x >= 1e9) {
				continue;
			}
			ans = min(ans, x + (long long)(cnt[i][j]));
		}
		return dp[i][k]= ans;
	}
	int palindromePartition(string s, int k) {
		int n = s.size();
		vector<vector<int>>cnt(n, vector<int>(n, 0));
		for (int i = 1; i < n; i++) {
			int l = 0, r = i;
			while (r < n) {
				cnt[l][r] = cnt[l + 1][r - 1] + (s[l] != s[r]);
				l++;
				r++;
			}
		}
		memset(dp, -1, sizeof(dp));
		return (int)calc(0, s, k, cnt);
	}
};