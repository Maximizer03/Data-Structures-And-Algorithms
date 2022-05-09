class Solution {
public:
	int dp[101][101][205];
	int calc(int i, int j, int sum, int n, int m, vector<vector<char>>&grid) {
		if (i >= n || j >= m || sum < 0 ) {
			return 0;
		}
		if (i == n - 1 && j == m - 1) {
			sum--;
			return (sum == 0);
		}
		if (dp[i][j][sum] != -1) {
			return dp[i][j][sum];
		}
		int rum = sum;
		if (grid[i][j] == '(') {
			rum++;
		}
		else {
			rum--;
		}
		int ans = calc(i + 1, j, rum, n, m, grid) | calc(i, j + 1, rum, n, m, grid);
		return dp[i][j][sum] = ans;

	}
	bool hasValidPath(vector<vector<char>>& grid) {
		int n = grid.size(), m = grid[0].size();
		if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(') {
			return false;
		}
		memset(dp, -1, sizeof(dp));
		return calc(0, 0, 0, n, m, grid);
	}
};