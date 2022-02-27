class Solution {
public:
	int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int laps) {
		int n = tires.size();
		vector<vector<int>>mat(n, vector<int>(20, 2e9));
		// mat[i][j]=> cost for tire i with success laps j
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < 20; j++) {
				if (j == 1) {
					mat[i][j] = tires[i][0];
				}
				else {
					long long pro = (long long )mat[i][j - 1] * tires[i][1];
					if (pro > 2e9) {
						break;
					}
					mat[i][j] = mat[i][j - 1] * tires[i][1];
				}
			}
			for (int j = 2; j < 20; j++) {
				if ((long long) mat[i][j] + mat[i][j - 1] >= 2e9) {
					break;
				}
				mat[i][j] += mat[i][j - 1];
			}
		}
		vector<int>dp(laps + 1, 2e9);
		for (int i = 1; i <= laps; i++) {
			if (i < 20) {
				for (int j = 0; j < n; j++) {
					dp[i] = min(dp[i], mat[j][i]);
				}
			}
			for (int j = i - 1; j > 0 && j >= i - 18; j--) {
				dp[i] = min(dp[i], dp[i - j] + changeTime + dp[j]);
			}
		}
		return dp[laps];
	}
};