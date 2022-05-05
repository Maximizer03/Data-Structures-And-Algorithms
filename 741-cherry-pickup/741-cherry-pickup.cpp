class Solution {
public:
    int dp[55][55][55];
	int calc(int i1, int j1, int j2, vector<vector<int>>&grid) {
		int n = grid.size();
		int i2 = i1 + j1 - j2;
		if (i1 >= n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
			return -1e8;
		}
		if (i1 == n - 1 && j1 == n - 1) {
			return grid[i1][j1];
		}
        if(dp[i1][j1][j2]!=-1){
            return dp[i1][j1][j2];
        }
		int ans = -1e8;
		int sum = 0;
		if (i1 == i2 && j1 == j2) {
			sum += grid[i1][j1];
		}
		else {
			sum += grid[i1][j1] + grid[i2][j2];
		}
		ans = max(ans, calc(i1 + 1, j1, j2, grid) + sum);
		ans = max(ans, calc(i1, j1 + 1, j2 + 1, grid) + sum);
		ans = max(ans, calc(i1 + 1, j1, j2 + 1, grid) + sum);
		ans = max(ans, calc(i1, j1 + 1, j2, grid) + sum);
		return dp[i1][j1][j2]=ans;
	}
	int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
		return max(0,calc(0, 0, 0, grid));
	}
};