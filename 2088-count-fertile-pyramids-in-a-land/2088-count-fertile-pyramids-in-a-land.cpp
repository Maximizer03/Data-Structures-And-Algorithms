class Solution {
public:
	int calc(vector<vector<int>>&a) {
		int n = a.size(), m = a[0].size();
		vector<vector<int>>dp(n, vector<int>(m, 0));
		int r = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) {
					r++;
					dp[i][j]++;
				}
			}
		}
        // dp[i][j]=> number of pyramids with apex at i,j
		int sum = 0;
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 1; j <= m - 2; j++) {
				if (dp[i][j] > 0) {
					dp[i][j] += min({dp[i + 1][j], dp[i + 1][j - 1], dp[i + 1][j + 1]});
					sum += dp[i][j] - 1;
				}
			}
		}
		return sum;
	}
	int countPyramids(vector<vector<int>>& grid) {
		int a1 = calc(grid);
		reverse(begin(grid), end(grid));
		a1 += calc(grid);
		return a1;
	}
};