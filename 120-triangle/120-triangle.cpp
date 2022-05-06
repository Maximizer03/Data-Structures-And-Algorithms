class Solution {
public:
	int dp[205][205];
	int calc(int i, int j, vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (j > i) {
			return 1e5;
		}
		if (i == n - 1) {
			return triangle[i][j];
		}
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		int ans = triangle[i][j] + min(calc(i + 1, j, triangle), calc(i + 1, j + 1, triangle));
		return dp[i][j]=ans;
	}
	int minimumTotal(vector<vector<int>>& triangle) {
		memset(dp, -1, sizeof(dp));
		return calc(0, 0, triangle);
	}
};