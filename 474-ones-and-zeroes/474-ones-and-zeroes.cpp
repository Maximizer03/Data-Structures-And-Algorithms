class Solution {
public:
	int findMaxForm(vector<string>& strs, int n, int m) {
		int s = strs.size();
		vector<vector<int>>cnt(s, vector<int>(2, 0));
		for (int i = 0; i < s; i++) {
			string t = strs[i];
			for (int j = 0; j < t.size(); j++) {
				cnt[i][(t[j] - '0')]++;
			}
		}
		int dp[s + 1][n + 1][m + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				dp[s][i][j] = 1;
			}
		}
		for (int i = s - 1; i >= 0; i--) {
			for (int x = 0; x <= n; x++) {
				for (int y = 0; y <= m; y++) {
					int ans = dp[i + 1][x][y];
					if (cnt[i][0] + x <= n && cnt[i][1] + y <= m) {
						ans = max(ans,  dp[i + 1][cnt[i][0] + x][cnt[i][1] + y] + 1);
					}
					dp[i][x][y] = ans;
				}
			}
		}
		return dp[0][0][0] - 1;
	}
};