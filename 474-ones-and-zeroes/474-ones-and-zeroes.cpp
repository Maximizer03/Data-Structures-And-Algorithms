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
		vector<vector<int>>prev(n + 1, vector<int>(m + 1));
		vector<vector<int>>cur(n + 1, vector<int>(m + 1));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				prev[i][j] = 1;
			}
		}
		for (int i = s - 1; i >= 0; i--) {
			for (int x = 0; x <= n; x++) {
				for (int y = 0; y <= m; y++) {
					int ans = prev[x][y];
					if (cnt[i][0] + x <= n && cnt[i][1] + y <= m) {
						ans = max(ans,  prev[cnt[i][0] + x][cnt[i][1] + y] + 1);
					}
					cur[x][y] = ans;
				}
			}
			swap(prev, cur);
		}
		return prev[0][0] - 1;
	}
};