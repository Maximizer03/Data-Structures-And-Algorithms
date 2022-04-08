class Solution {
public:
	int dp[105][25][105];
	int calc(int i, int col, int cnt, int target, vector<int>& houses, vector<vector<int>>& cost, int m, int n) {
		if (i == m) {
			if (cnt == target) {
				return 0;
			}
			else {
				return 1e8;
			}
		}
		if (dp[i][col][cnt] != -1) {
			return dp[i][col][cnt];
		}
		int ans = 1e8;
		if (houses[i] == 0) {
			for (int j = 0; j < n; j++) {
				if (j + 1 == col) {
					ans = min(ans, calc(i + 1, col, cnt, target, houses, cost, m, n) + cost[i][j]);
				}
				else {
					ans = min(ans, calc(i + 1, j + 1, cnt + 1, target, houses, cost, m, n) + cost[i][j]);
				}
			}
		}
		else {
			if (houses[i] != col) {
				ans = min(ans, calc(i + 1, houses[i], cnt + 1, target, houses, cost, m, n));
			}
			else {
				ans = min(ans, calc(i + 1, col, cnt, target, houses, cost, m, n));
			}
		}
		return dp[i][col][cnt] = ans;
	}
	int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
		memset(dp, -1, sizeof(dp));
		int ans = calc(0, 0, 0, target, houses, cost, m, n);
		if (ans == 100000000) {
			return -1;
		}
		else {
			return ans;
		}
	}
};